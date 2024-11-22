#include "../include/crypt.hh"
#include <stdexcept>

using namespace crypto;

cryptosys::cryptosys() {};

cryptosys::~cryptosys() {};

std::string cryptosys::generateSalt() {
    unsigned char salt[32]; // 256 bit salt. Salty! Not sweet really.
    if (RAND_bytes(salt, sizeof(salt)) != 1) {
        throw std::runtime_error("Failed to generate cryptographic salt");
    }
    return std::string(reinterpret_cast<char*>(salt), sizeof(salt));
}

std::string cryptosys::hashPassword(const std::string& password, const std::string& salt) {
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (!ctx) {
        throw std::runtime_error("Failed to create hash context");
    }

    // Initialize with SHA-256
    if (EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr) != 1) {
        EVP_MD_CTX_free(ctx);
        throw std::runtime_error("Failed to initialize hash");
    }

    // Hash salt + password
    std::string salted = salt + password;
    if (EVP_DigestUpdate(ctx, salted.c_str(), salted.length()) != 1) {
        EVP_MD_CTX_free(ctx);
        throw std::runtime_error("Failed to update hash");
    }

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLen;
    if (EVP_DigestFinal_ex(ctx, hash, &hashLen) != 1) {
        EVP_MD_CTX_free(ctx);
        throw std::runtime_error("Failed to finalize hash");
    }

    EVP_MD_CTX_free(ctx);
    return std::string(reinterpret_cast<char*>(hash), hashLen);
}

std::string cryptosys::base64Encode(const std::string& input) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    // create new base64 filter BIO
    b64 = BIO_new(BIO_f_base64());

    // dont add newlines - write everything in one line
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

    // create a memory bio and chain it with the base64 filter
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    // write the data
    BIO_write(bio, input.c_str(), input.length());
    BIO_flush(bio);

    // get encoded data
    BIO_get_mem_ptr(bio, &bufferPtr);
    std::string output(bufferPtr->data, bufferPtr->length);

    // clean up
    BIO_free_all(bio);

    return output;
}

std::string cryptosys::getSecureInput(const std::string& prompt) {
        std::string password;
        struct termios old_settings, new_settings;

        // get current term settings
        tcgetattr(STDIN_FILENO, &old_settings);
        new_settings = old_settings;
        // disable echo!
        new_settings.c_lflag &= ~ECHO;

        // apply new settings
        tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

        // show prompt get input
        std::cout << prompt;
        std::getline(std::cin, password);
        std::cout << std::endl; // still a buffer flussher

        // restore old settings
        tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);

        return password;
}

