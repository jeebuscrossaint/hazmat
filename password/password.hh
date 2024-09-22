#ifndef PASSWORD_H
#define PASSWORD_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

class Password {
public:
    void listPasswords();
    void addPassword(const std::string& listName, const std::string& username, const std::string& hint, const std::string& passwordValue);

private:
    std::string listName;
    std::string username;
    std::string hint;
    std::string passwordValue;
};

#endif // PASSWORD_H