#include "cli.hh"
#include "../list/list.hh"
#include <iostream>
#include <cstdlib> // For std::exit
#include "../password/password.hh"

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
        } 
        
        if (command == "add") {
            if (argc > 2) {
                std::string subcommand = argv[2];
                if (subcommand == "password") {
                    /*std::string listName, username, hint, passwordValue;
                    std::cout << "Enter the username to add (leave blank if none): ";
                    std::getline(std::cin, username);
                    std::cout << "Enter the password: ";
                    std::getline(std::cin, passwordValue);
                    std::cout << "Enter which list to add to (leave blank if master): ";
                    std::getline(std::cin, listName);
                    std::cout << "Enter a hint (optional, can be a path to an image if you use visual password hints.): ";   
                    std::getline(std::cin, hint);

                    Password password;
                    password.addPassword(listName, username, hint, passwordValue); */
                    Password password;
                    password.promptAndAddPassword();
                }   
            } else {
                const std::string red = "\033[31m";
                const std::string reset = "\033[0m";
                std::cerr << "Error: You need to add a subcommand, " << red << "idiot" << reset << "!" << std::endl;
                std::cout << "Possible subcommands: password username hint\n";
                std::exit(EXIT_FAILURE);
            }
        } 
    } else {
        printHelp();
    }
}

void password_manager_cli::printHelp() {
    const std::string green = "\033[32m";
    const std::string boldGreen = "\033[1;32m";
    const std::string reset = "\033[0m";

    std::cout << boldGreen << "  \nhazmat - the greatest password manager for the neckbeard dweller.\n" << reset;
    std::cout << boldGreen << "  \nUsage: hazmat <command> [subcommand] [options]\n" << reset;
    std::cout << green << "      hazmat list\n" << reset;
    std::cout << green << "      hazmat add\n" << reset;
    std::cout << green << "      hazmat delete\n" << reset;
    std::cout << green << "      hazmat update\n" << reset;
    std::cout << green << "      hazmat show\n" << reset;
    std::cout << green << "      hazmat help\n" << reset;

    std::cout << boldGreen << "  \nIf this is your first time using the program and you didn't read the docs, read them or do hazmat help <command>, [list, add, delete, update, show, help] being the available commands.\n" << reset;
}
