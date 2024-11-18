#include "../include/entry.hh"
#include "../include/setup.hh"
#include "../include/crypt.hh"
#include "../include/help.hh"

int main(int argc, char* argv[]) {
    entry::Entry entry;
    setup::SETUP setup;

    setup.setupdir();

    if (argc > 2 && std::string(argv[1]) == "import") {
        std::string filepath = argv[2];
        setup.importcsv(&filepath);
    }
    if (argc > 1 && std::string(argv[1]) == "help") {
        printhelp();
    }
    return 0;
}