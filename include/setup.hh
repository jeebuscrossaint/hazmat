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
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#include "entry.hh"

namespace setup {

class SETUP {
        public:
                // Constructors and Destructors
                SETUP();
                ~SETUP();

                // lock file function
                bool createlockfile();
                // csv to hazmat program conversion so that way the user can import their browser entries!
                void importcsv(std::string* csvinput);

                std::vector<entry::EntryData> parseCSV(const std::string& csvLine);
                
                // hazmat to csv conversion so the user can export data if they quit using my lovely program :(
                void convert(std::vector<entry::EntryData>* entries);
                
                // setup function for the first time the program is ran
                void setupdir();

                void exportcsv();
;
};

}

#endif // SETUP_HH