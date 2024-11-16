#include "../include/setup.hh"
#include "../include/crypt.hh"

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
        
        //crypto::cryptosys crypto;
        std::string masterPass = crypto::cryptosys::getSecureInput("Enter new master password: ");
        std::string confirmPass = crypto::cryptosys::getSecureInput("Confirm master password: ");

        if (masterPass != confirmPass) {
            std::cerr << "Passwords do not match!" << std::endl;
            return;
        }

        // Generate salt and hash password
        std::string salt = crypto::cryptosys::generateSalt();
        std::string hashedPass = crypto.hashMasterPassword(masterPass);
        
        // Store master password data
        std::ofstream mfile(master_file);
        if (mfile.is_open()) {
            mfile << crypto::cryptosys::base64Encode(salt) << std::endl;
            mfile << crypto::cryptosys::base64Encode(hashedPass) << std::endl;
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