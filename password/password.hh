#ifndef PASSWORD_H
#define PASSWORD_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

class Password {
public:
    void listPasswords();
    void addPassword(const std::string& listName, const std::string& username, const std::string& hint);

private:
    // idfk add private functions and atrributes here later
    std::string listName;
    std::string username;
    std::string hint;
    
};

#endif // PASSWORD_H