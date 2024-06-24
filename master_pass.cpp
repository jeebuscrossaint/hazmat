#include <iostream>
#include <string>
#include <argon2.h>
#include <iomanip>
#include <termios.h>

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

int get_stupid_string() {
    std::cout << "\n";
    std::string super_obfuscated_password_please_dont_look_here_ok;
    char jit;
    while ((jit = getch()) != '\n') {
        super_obfuscated_password_please_dont_look_here_ok += jit;
        std::cout << "";
    }

    std::cout << std::endl;
    std::cout << "Decripting..."; << std::endl;
    return 0;
}
