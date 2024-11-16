#include "../include/crypt.hh"

using namespace crypto;

std::string cryptosys::getSecureInput(const std::string& prompt) {
        std::string password;
        struct termius old_settings, new_settings;

        // get current term settings
        tcgetattr(STDIN_FILENO, &old_settings);
        new_settings = old_settings

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

