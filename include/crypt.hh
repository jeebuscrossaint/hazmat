#ifndef CRYPT_HH
#define CRYPT_HH
#include "entry.hh"
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <random>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <stdexcept>


namespace crypto {

class cryptosys{
        public:
                cryptosys();
                ~cryptosys();
                std::string getSecureInput(const std::string& prompt);
                std::string hashPassword(const std::string& password, const std::string& salt);  // For master password
                std::string generateSalt();
                std::string encryptData(const std::string& data, const std::string& key);
                std::string base64Encode(const std::string& data);
                std::string base64Decode(const std::string& data);
                std::string decryptData(const std::string& encrypted, const std::string& key);  // For retrieving passwords
};

};

#endif // CRYPT_HH