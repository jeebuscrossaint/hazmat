// master_pass.h

#ifndef MASTER_PASS_H
#define MASTER_PASS_H

#include <string>
#include <iostream>

class master_pass {

public:
	master_pass();
	~master_pass();

std::string get_stupid_string();
int criptoegraphee(std::string& str);


private:
	string super_obfuscated_password_please_dont_look_here_ok;
	int num_attempts;
	int max_attempts;
	int time;
	int timeout_time;
}

#endif // MASTER_PASS_H

