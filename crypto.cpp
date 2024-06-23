#incldue "encrypt.h"
#include <argon2.h> // argon2 lib

std::string hash_password(const std::string& password) {
    // hash password with argon2
    return argon2i_hash_raw(password.c_str(), password.length());
}
