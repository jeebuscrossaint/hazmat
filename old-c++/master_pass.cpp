#include <iostream>
#include <string>
#include <argon2.h>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
#include "master_pass.h" 


master_pass master_pass::base_instance;

char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) 
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return (buf);
}

master_pass::master_pass() {
    super_obfuscated_password_please_dont_look_here_ok = "";
    int num_attempts = 0;
    int max_attempts = super_configurable_value();
    int time = 0;
    int timeout_time = super_configurable_value();
};

master_pass::~master_pass() {

};

std::string master_pass::get_stupid_string() {
    std::cout << "\n";
    std::string super_obfuscated_password_please_dont_look_here_ok;
    char jit;
    while ((jit = getch()) != '\n') {
        super_obfuscated_password_please_dont_look_here_ok += jit;
        std::cout << "";
    }

    std::cout << std::endl;
    std::cout << "Decripting..."; << std::endl;
    return "";
}

int master_pass::criptoegraphee(const std::string& str) {
    
}
