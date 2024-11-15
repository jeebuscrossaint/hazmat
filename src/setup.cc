#include "../include/setup.hh"

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
                std::cerr << "You dont have a home directory? What are you, homeless?" << std::endl; // they call me the buffer flusher
                return;
        }
        std::string hazmatdir = std::string(env_home) + "/.hazmat"; 
        if (hazmatdir.empty()) {
                std::cout << "Seems like this is your first rodeo... at least you have a roof over your head.";
                fs::create_directory(hazmatdir);
                return;
        }
        std::cout << "Well, you already have a home and a .hazmat dir, good to know you came well prepared." << std::endl;
};

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
        return;
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
                        std::getline(ss, entry.httpRealm, ',');
                        std::getline(ss, entry.formActionOrigin, ',');
                        std::getline(ss, entry.guid, ',');
                        std::getline(ss, entry.timeCreated, ',');
                        std::getline(ss, entry.timeLastUsed, ',');
                        std::getline(ss, entry.timePasswordChanged, ',');
                        entry.isImported = true;
                        entries.push_back(entry);
                }
        }
        return entries;
}

void SETUP::exportcsv() {


};