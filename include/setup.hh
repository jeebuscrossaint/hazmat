#ifndef SETUP_HH
#define SETUP_HH

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <filesystem>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstdlib>

namespace setup {

class SETUP {
        private:
        // Constructors and Destructors
        SETUP();
        ~SETUP();

        // setup function for the first time the program is ran
        void setup();

        // csv to hazmat program conversion so that way the user can import their browser entries!
        void inportcsv(std::string* csvinput);

        void convert(std::string* csvinput);
        // hazmat to csv conversion so the user can export data if they quit using my lovely program :(
        void exportcsv();

        std::vector<
};

}

#endif // SETUP_HH