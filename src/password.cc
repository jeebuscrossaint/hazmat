#include "../include/password.hh"
#include "../include/master.hh"

std::string getPassword(const std::string& prompt) {
    std::cout << prompt;
    std::string password;
    char ch;
    struct termios oldt, newt;

    // Turn off terminal echo
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while ((ch = getchar()) != '\n' && ch != EOF) {
        password.push_back(ch);
        std::cout << '*';
    }

    // Restore terminal echo
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    std::cout << std::endl;

    return password;
}

void Password::addPassword(const std::string& listName, const std::string& username, const std::string& hint, const std::string& passwordValue) {
    this->listName = listName;
    this->username = username;
    this->hint = hint;
    this->passwordValue = passwordValue;

    std::cout << "\nPassword added to list " << listName << " with the following details:";
    std::cout << "\nUsername: " << username;
    std::cout << "\nList: " << listName;
    std::cout << "\nHint: " << hint;
    std::cout << "\nPassword: " << std::string(passwordValue.length(), '*');
}

void Password::promptAndAddPassword() {
    std::string listName, username, hint, password1, password2;

    std::cout << "Enter the username to add (leave blank if none): ";
    std::getline(std::cin, username);
    std::cout << "Enter which list to add to (leave blank if master): ";
    std::getline(std::cin, listName);
    std::cout << "Enter a hint (optional, can be a path to an image if you use visual password hints.): ";
    std::getline(std::cin, hint);

    do {
        password1 = getPassword("Enter the password (it will not echo): ");
        password2 = getPassword("Re-enter the password: ");

        if (password1 != password2) {
            std::cout << "Passwords do not match. Please try again.\n";
        }
    } while (password1 != password2);

    addPassword(listName, username, hint, password1);
}