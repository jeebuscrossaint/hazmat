#include "../include/entry.hh"

using namespace userpass;

Entry::Entry() {
    this->username = "";
    this->password = "";
    this->website = "";
    this->email = "";
    this->hints = "";
    this->description = "";
    this->date_and_time = "";
}

Entry::~Entry() {
    this->username = "";
    this->password = "";
    this->website = "";
    this->email = "";
    this->hints = "";
    this->description = "";
    this->date_and_time = "";
}

