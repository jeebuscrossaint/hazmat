#include "cli.hh"

#include <iostream>

void password_manager_cli::run(int argc, char **argv) {
    printHelp();
}

void password_manager_cli::printHelp() {
    const std::string green = "\033[32m";
    const std::string boldGreen = "\033[1;32m";
    const std::string reset = "\033[0m";

    std::cout << boldGreen << "  hazmat - the greatest password manager for the neckbeard dweller.\n" << reset;

    std::cout << green << "      hazmat list\n" << reset;
    std::cout << green << "      hazmat add\n" << reset;
    std::cout << green << "      hazmat delete\n" << reset;
    std::cout << green << "      hazmat update\n" << reset;
    std::cout << green << "      hazmat show\n" << reset;
    std::cout << green << "      hazmat help\n" << reset;

    std::cout << boldGreen << "  If this is your first time using the program and you didn't read the docs, read them or do hazmat help <command>, [list, add, delete, update, show, help] being the available commands.\n" << reset;
}