
#include <iostream>
#include <iomanip>
#include <cstring>
#include <argon2.h>

void hash_password(const std::string& password, const std::string& salt, uint32_t t_cost, uint32_t m_cost, uint32_t parallelism, uint32_t hash_len) {
    unsigned char hash[hash_len];
    memset(hash, 0, hash_len);

    int result = argon2id_hash_raw(t_cost, m_cost, parallelism,
                                   password.c_str(), password.size(),
                                   salt.c_str(), salt.size(),
                                   hash, hash_len);

    if (result != ARGON2_OK) {
        std::cerr << "Error: " << argon2_error_message(result) << std::endl;
        return;
    }

    std::cout << "Hash: ";
    for (size_t i = 0; i < hash_len; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    std::cout << std::endl;
}

