#ifndef LIBHAZ_HH
#define LIBHAZ_HH

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace hazmat {

        struct EntryData {
                std::string url;
                std::string username;
                std::string password;
                std::string timeCreated;
                std::string timeLastUsed;
                std::string timePasswordChanged;
        };


        class suit {
        public:
            suit();
            ~suit();

            // CSV operations
            std::vector<EntryData> parse(const std::string& csvLine);
            void convert(const std::vector<EntryData>& entries, const std::string& outPath);
            void suitexport(const std::string& hazmatFile, const std::string& outPath);
            
            // Entry operations (moved from entry.cc)
            void addEntry(const std::string& username, const std::string& password);
            void addEntry(const std::string& username, const std::string& password, const std::string& url);
            void addEntry(EntryData entry);

        private:
            std::string formatentry(const EntryData& entry);
            std::vector<EntryData> entries;
    };
}


#endif // LIBHAZ_HH