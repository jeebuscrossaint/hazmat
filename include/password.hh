#ifndef PASSWORD_H
#define PASSWORD_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <termios.h>
#include <unistd.h>

class Password {
public:
    void listPasswords();
    void addPassword(const std::string& listName, const std::string& username, const std::string& hint, const std::string& passwordValue);
    void promptAndAddPassword();

private:
    std::string listName;
    std::string username;
    std::string hint;
    std::string passwordValue;
    std::string prompt;
};

std::string getPassword(const std::string& prompt);

#endif // PASSWORD_H