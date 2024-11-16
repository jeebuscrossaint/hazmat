#ifndef CRYPT_HH
#define CRYPT_HH
#include "entry.hh"
#include <termios.h>
#include <unistd.h>
#include <iostream>

namespace crypto {

class cryptosys{
        public:
                cryptosys();
                ~cryptosys();
                std::string getSecureInput(const std::string& prompt);
                std::string hashMasterPassword(const std::string& masterPassword);
                std::string generateSalt();
                std::string deriveKey(const std::string& hashedPassword);
                std::string encryptData(const std::string& data, const std::string& key);
                std::string base64Encode(const std::string& data);
                void storeData(const std::string& encodedData, const std::string& salt);
                std::string decryptData(const std::string& encodedData, const std::string& key);
};

};

#endif // CRYPT_HH