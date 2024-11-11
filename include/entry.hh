#ifndef ENTRY_HH
#define ENTRY_HH

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

namespace userpass {

class Entry {
        public:
                std::string username;
                std::string password;
                std::string website;
                std::string email;
                std::string hints;
                std::string description;
                std::string date_and_time;

                // Constructors and Destructors
                Entry();
                ~Entry();

                // Methods
                // i am going to make a lot of overloads for this method
                void addEntry(const std::string& username, const std::string& password);
                void addEntry(const std::string& username, const std::string& password, const std::string& website);
                void addEntry(const std::string& username, const std::string& password, const std::string& website, const std::string& email);
                void addEntry(const std::string& username, const std::string& password, const std::string& website, const std::string& email, const std::string& hints);
                void addEntry(const std::string& username, const std::string& password, const std::string& website, const std::string& email, const std::string& hints, const std::string& description);
                void addEntry(const std::string& username, const std::string& password, const std::string& website, const std::string& email, const std::string& hints, const std::string& description, const std::string& date);

};

}

#endif // ENTRY_HH