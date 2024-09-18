#include "cli.hh"
#include "../list/list.hh"
#include <iostream>
#include <cstdlib> // For std::exit

void password_manager_cli::run(int argc, char **argv) {
    if (argc > 1) {
        std::string command = argv[1];
        if (command == "list") {
            if (argc > 2) {
                std::string subcommand = argv[2];
                if (subcommand == "add") {
                    std::string name, description, hint;
                    std::cout << "Enter the name of the new list: ";
                    std::getline(std::cin, name);
                    std::cout << "Enter a description (optional): ";
                    std::getline(std::cin, description);
                    std::cout << "Enter a hint (optional): ";
                    std::getline(std::cin, hint);

                    List list;
                    list.addList(name, description, hint);
                }
            } else {
                const std::string red = "\033[31m";
                const std::string reset = "\033[0m";
                std::cerr << "Error: You need to add a subcommand, " << red << "idiot" << reset << "!" << std::endl;
                std::cout << "Possible subcommands: add update list delete\n";
                std::exit(EXIT_FAILURE);
            }
        } else {
            printHelp();
        }
    } else {
        printHelp();
    }
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