#include "../include/setup.hh"

using namespace setup;
namespace fs = std::filesystem;

SETUP::SETUP() {
        // Empty
}

SETUP::~SETUP() {
        // Empty
}

void SETUP::setup() {
        const char* env_home = std::getenv("$HOME");
        if (env_home == nullptr) {
                std::cerr << "You dont have a home directory? What are you, homeless?" << std::endl; // they call me the buffer flusher
                std::abort;
        }
        std::string hazmatdir = std::string(env_home) + "/.hazmat"; 
        fs::create_directory(hazmatdir);
};

void SETUP::inportcsv(std::string* csvinput) {
        
};

void SETUP::exportcsv() {


};