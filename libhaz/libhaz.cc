#include "libhaz.hh"

namespace hazmat {

suit::suit() {}
suit::~suit() {}

std::vector<EntryData> suit::parse(const std::string& csvLine) {
    std::vector<EntryData> entries;
    std::stringstream ss(csvLine);
    std::string token;
    EntryData entry;

    while (std::getline(ss, token, ',')) {
        token.erase(
            remove(token.begin(), token.end(), '\"'),
            token.end()
        );

        if (!token.empty()) {
            entry.url = token;
            std::getline(ss, entry.username, ',');
            std::getline(ss, entry.password, ',');
            std::getline(ss, entry.timeCreated, ',');
            std::getline(ss, entry.timeLastUsed, ',');
            std::getline(ss, entry.timePasswordChanged, ',');
            entries.push_back(entry);
        }
    }
    return entries;
}

void suit::convert(const std::vector<EntryData>& entries, const std::string& outPath) {
    std::ofstream outfile(outPath);
    if (!outfile.is_open()) return;

    // Write header
    outfile << "? * |" << std::endl;
    outfile << "\"url\"" << std::endl;
    outfile << "\"username\"" << std::endl;
    outfile << "\"password\"" << std::endl;
    outfile << "\"timeCreated\"" << std::endl;
    outfile << "\"timeLastUsed\"" << std::endl;
    outfile << "\"timePasswordChanged\"" << std::endl;
    outfile << "| * ?" << std::endl << std::endl;

    // Write entries
    for (size_t i = 0; i < entries.size(); i++) {
        outfile << std::string(i + 1, ';') << " [" << std::endl;
        outfile << formatentry(entries[i]);
        outfile << "]" << std::endl;
    }
}

std::string suit::formatentry(const EntryData& entry) {
    std::stringstream ss;
    ss << "\"" << entry.url << "\"" << std::endl;
    ss << "\"" << entry.username << "\"" << std::endl;
    ss << "\"" << entry.password << "\"" << std::endl;
    ss << "\"" << entry.timeCreated << "\"" << std::endl;
    ss << "\"" << entry.timeLastUsed << "\"" << std::endl;
    ss << "\"" << entry.timePasswordChanged << "\"" << std::endl;
    return ss.str();
}

void suit::addEntry(const std::string& username, const std::string& password) {
    EntryData entry;
    entry.username = username;
    entry.password = password;
    entries.push_back(entry);
}

void suit::addEntry(const std::string& username, const std::string& password, const std::string& url) {
    EntryData entry;
    entry.username = username;
    entry.password = password;
    entry.url = url;
    entries.push_back(entry);
}

void suit::addEntry(EntryData entry) {
    entries.push_back(entry);
}

void suit::suitexport(const std::string& hazmatFile, const std::string& outPath) {
    // Implement export from hazmat format to CSV
    // TODO: Add implementation
}

}