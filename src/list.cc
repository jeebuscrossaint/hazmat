#include "list.hh"

void List::listLists() {
    std::cout << "\n this will print a big ol list of existing lists";
}

void noArgs() {
    // impl of if user does not append an argument
}

void List::addList(const std::string& name, const std::string& description, const std::string& hint) {
    this->name = name;
    this->description = description;
    this->hint = hint;

    std::cout << "\nList created with the following details:";
    std::cout << "\nName: " << name;
    std::cout << "\nDescription: " << description;
    std::cout << "\nHint: " << hint;
}