#ifndef MASTER_PASSWORD_H
#define MASTER_PASSWORD_H

#include <string> 
#include <vector>
#include <argon2.h>
#include <stdexcept>
#include <random>
#include <iomanip>
#include <sstream>

class master_password {
    public:
    std::string hasher(const std::string& input);
    std::vector<uint8_t> generateSalt(size_t length);

    private:
        const uint32_t t_cost = 5; // iter count
        const uint32_t m_cost = (1 << 16) * 4; //memory count (1 << 16) * 4 = 64MB
        const uint32_t parallelism = 4; // number of threads
        const uint32_t hash_length = 32; // hash length
};

#endif // MASTER_PASSWORD_H