#include "password.hh"
#include "../list/list.hh"

void Password::addPassword(const std::string& listName, const std::string& username, const std::string& hint) {
    this->listName = listName;
    this->username = username;
    this->hint = hint;

    std::cout << "\nPassword added to list " << listName << " with the following details:";
    std::cout << "\nUsername: " << username;
    std::cout << "\nHint: " << hint;
}