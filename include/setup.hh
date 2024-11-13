#ifndef SETUP_HH
#define SETUP_HH

#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

namespace setup {

class Setup {
        public:
        // Constructors and Destructors
        Setup();
        ~Setup();

        // setup function for the first time the program is ran
        void setup();

        // csv to hazmat program conversion so that way the user can import their browser entries!
        void convert();

};

}

#endif // SETUP_HH