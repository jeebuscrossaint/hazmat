#ifndef CLI_H
#define CLI_H

#include <string>
#include <map>

class password_manager_cli {
    public:
    void run(int argc, char* argv[]);

    private:
    void createList(const std::string& listName);
    void showLists();
    void addPassword(const std::string& listName, const std::string& serviceName);
    void getPassword(const std::string& listName, const std::string& serviceName);
    void deleteList(const std::string& listName);
    void printHelp();
    void getUsername(const std::string& listName);
    void deletePassword(const std::string& listName, const std::string& serviceName);
    void deleteUsername(const std::string& listName, const std::string& serviceName);
    

    // Store lists with master passwords (for now)
    std::map<std::string, std::string> lists;
};

#endif // CLI_H