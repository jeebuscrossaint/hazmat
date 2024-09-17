#ifndef LIST_H
#define LIST_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

class List {
public:
    void listLists();
    void addList(const std::string& name, const std::string& description, const std::string& hint);

private:
    std::string name;
    std::string description;
    std::string hint;

    void showList();
    void deleteList();
    void updateList();
    void addDescription();
    void deleteDescription();
    void updateDescription();
    void addHint();
    void deleteHint();
    void updateHint();
    void noArgs();
};


#endif // LIST_H