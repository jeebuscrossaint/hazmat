#include "db.h"
#include "crypto.h"
#include <iostream>
#include <string>
#include <unistd.h>

void print_help() {
    std::cout << "Usage: cppipher [options] command\n"
              << "Options: \n"
              << " -h, --help    Show this help message\n"
              << "Commands: \n"
              << " list create [name]    Create a new list with the given name\n"
              << std::endl;
}

int ask_for_help() {
    std::cout << "Do you need help? (y/n): ";
    std::string response;
    std::cin >> response;
    if (response == "y") {
        print_help();
    }

    if (response == "n") {
        return 0;
    }

    else {
        return 1;
    }
}

int main(int argc, char* argv[]) {
    int opt;
    bool opt_found = false;

    while ((opt = getopt(argc, argv, "h")) != -1) {
        opt_found = true;
        switch (opt) {
            case 'h':
                print_help();
                return 0;
            default:
                ask_for_help();
        }
    }

    if (!opt_found) {
        if (argc < 4) {
            std::cerr << "Error: Missing command\n";
            print_help();
            return 1;
        }

        std::string command = argv[1];
        std::string subcommand = argv[2];
        std::string name = argv[3];

        if (command == "list" && subcommand == "create") {
		std::cout << "Psst! Dont let anyone see this! Enter a master password: ";
		std::string password;
		std::cin >> password;

		std::string hashed_password = hash_password(password);
	
		create_list(name, hashed_password);
        } else {
            std::cerr << "Error: Unknown command\n";
            print_help();
            return 1;
        }
    }

    return 0;
}

