#include "master.hh"

std::vector<uint8_t> master_password::generateSalt(size_t length) {
    std::random_device rd;
    std::vector<uint8_t> salt(length);
    for (size_t i = 0; i < length; ++i) {
        salt[i] = rd() % 256;
    }

    return salt;
}

std::string master_password::hasher(const std::string& input) {
    const size_t salt_length = 16;
    std::vector<uint8_t> salt = generateSalt(salt_length);
    std::vector<uint8_t> hash(hash_length);

    int result = argon2id_hash_raw(t_cost, m_cost, parallelism,
                                    input.data(), input.size(),
                                    salt.data(), salt.size(), 
                                    hash.data(), hash.size());
    
    if (result != ARGON2_OK) {
        throw std::runtime_error("Hashing with Argon2id failed");
    }

    std::ostringstream oss;
    for(auto byte : salt) {
        oss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(byte);
    }
    for (auto byte : hash) {
        oss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(byte);
    }

    return oss.str();
}