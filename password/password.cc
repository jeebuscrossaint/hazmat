#include "password.hh"
#include "../list/list.hh"

void Password::addPassword(const std::string& listName, const std::string& username, const std::string& hint, const std::string& passwordValue) {
    this->listName = listName;
    this->username = username;
    this->hint = hint;
    this->passwordValue = passwordValue;

    std::cout << "\nPassword added to list " << listName << " with the following details:";
    std::cout << "\nUsername: " << username;
    std::cout << "\nHint: " << hint;
    std::cout << "\nPassword: " << std::string(passwordValue.length(), '*');
}