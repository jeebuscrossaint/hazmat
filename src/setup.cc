#include "../include/setup.hh"
#include "../include/crypt.hh"
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <ostream>
#include <string>

using namespace setup;
namespace fs = std::filesystem;

SETUP::SETUP() {
        // Empty
}

SETUP::~SETUP() {
        // Empty
}

void SETUP::setupdir() {
    const char* env_home = std::getenv("HOME");
    if (env_home == nullptr) {
        std::cerr << "You dont have a home directory? What are you, homeless?" << std::endl;
        return;
    }
    
    std::string hazmatdir = std::string(env_home) + "/.hazmat";
    std::string master_file = hazmatdir + "/master.key";
    
    // Create .hazmat directory if it doesn't exist
    if (!fs::exists(hazmatdir)) {
        std::cout << "Creating hazmat directory..." << std::endl;
        fs::create_directory(hazmatdir);
    }

    // Check if master password exists
    if (!fs::exists(master_file)) {
        std::cout << "First time setup - creating master password" << std::endl;
        
        crypto::cryptosys crypto; // Create an instance of cryptosys
        std::string masterPass = crypto.getSecureInput("Enter new master password: ");
        std::string confirmPass = crypto.getSecureInput("Confirm master password: ");

        if (masterPass != confirmPass) {
            std::cerr << "Passwords do not match!" << std::endl;
            return;
        }

        // Generate salt and hash password
        std::string salt = crypto.generateSalt();
        std::string hashedPass = crypto.hashMasterPassword(masterPass);
        
        // Store master password data
        std::ofstream mfile(master_file);
        if (mfile.is_open()) {
            mfile << crypto.base64Encode(salt) << std::endl;
            mfile << crypto.base64Encode(hashedPass) << std::endl;
            mfile.close();
        }
    }
}

void SETUP::importcsv(std::string* csvinput) {
        // check if file exists because im not aboutta abrot for no reason
        std::ifstream file(*csvinput);
        if (!file.is_open()) {
                std::cerr << "Error: Could not open file " << *csvinput << std::endl;
                return;
        }

        std::string line;
        std::vector<entry::EntryData> allEntries;

        // skip header since thats the key line
        std::getline(file, line);

        // read each lin and parse
        while (std::getline(file, line)) {
                std::vector<entry::EntryData> entries = parseCSV(line);
                allEntries.insert(allEntries.end(), entries.begin(), entries.end());
        }

        file.close();

        // call convert function to store in proprietary format!
        convert(&allEntries);
};

void SETUP::convert(std::vector<entry::EntryData>* entries) {
        const char* env_home = std::getenv("HOME");
    if (env_home == nullptr) {
        std::cerr << "Error: HOME environment variable not set" << std::endl;
        return;
    }

    // Create full paths
    std::string hazmatdir = std::string(env_home) + "/.hazmat";
    std::string entriesfile = hazmatdir + "/entries.db";

    // Ensure .hazmat directory exists
    if (!fs::exists(hazmatdir)) {
        if (!fs::create_directory(hazmatdir)) {
            std::cerr << "Error: Could not create .hazmat directory" << std::endl;
            return;
        }
    }

    // Open file with full path
    std::ofstream outfile(entriesfile);
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create entries file at " << entriesfile << std::endl;
        return;
    }

        // write header/key paragraph
        outfile << "? * |" << std::endl;
        outfile << "\"url\"" << std::endl;
        outfile << "\"username\"" << std::endl;
        outfile << "\"password\"" << std::endl;
        outfile << "\"timeCreated\"" << std::endl;
        outfile << "\"timeLastUsed\"" << std::endl;
        outfile << "\"timePasswordChanged\"" << std::endl;
        outfile << "| * ?" << std::endl << std::endl;

        // write entries
        for (size_t i = 0; i < entries->size(); i++) {
                //create semicolon index markers
                outfile << std::string(i+1, ';') << "  [" << std::endl;

                const auto& entry = entries->at(i);
                outfile << "\"" << entry.url << "\"" << std::endl;
                outfile << "\"" << entry.username << "\"" << std::endl;
                outfile << "\"" << entry.password << "\"" << std::endl;
                outfile << "\"" << entry.timeCreated << "\"" << std::endl;
                outfile << "\"" << entry.timeLastUsed << "\"" << std::endl;
                outfile << "\"" << entry.timePasswordChanged << "\"" << std::endl;
        
                outfile << "]" << std::endl;
        }

        outfile.close();
};


std::vector<entry::EntryData> SETUP::parseCSV(const std::string& csvLine) {
        std::vector<entry::EntryData> entries;
        std::stringstream ss(csvLine);
        std::string token;

        entry::EntryData entry;

        // parse csv line by line

        while (std::getline(ss, token, ',')) {
                // remove quotes if present
                token.erase(
                        remove(token.begin(), token.end(), '\"'),
                        token.end()
                );

                // fill the struct field in order
                if (!token.empty()) {
                        entry.url = token;
                        std::getline(ss, entry.username, ',');
                        std::getline(ss, entry.password, ',');
                        std::getline(ss, entry.timeCreated, ',');
                        std::getline(ss, entry.timeLastUsed, ',');
                        std::getline(ss, entry.timePasswordChanged, ',');
                        entries.push_back(entry);
                }
        }
        return entries;
}

void SETUP::exportcsv() {


};

bool SETUP::createlockfile() {
        const char* tempdir = "/tmp";
        std::string lockfile = std::string(tempdir) + "/hazmat.lock";

        // check if the lockfile exists
        if (fs::exists(lockfile)) {
                // check the existing PID, if there is one.
                std::ifstream existing_lock(lockfile);
                pid_t existing_pid;
                existing_lock >> existing_pid;
                existing_lock.close();

                // check if the process is still running
                if (kill(existing_pid, 0) == 0) {
                        std::cerr << "hazmat is already running (PID: " << existing_pid << ")" << std::endl;
                        return false;
                }

                // stale lock file? KILL IT!!
                fs::remove(lockfile);
        }

        // create a new lock file
        std::ofstream lock(lockfile);
        if (!lock.is_open()) {
                std::cerr << "Could not create lock file" << std::endl;
                return false;
        }

        // write current PID to lock
        pid_t current_pid = getpid();
        lock << current_pid << std::endl;
        lock.close();

        //register cleanup handler
        std::atexit([]() {
                fs::remove("/tmp/hazmat.lock");
        });
        
        return true;
}