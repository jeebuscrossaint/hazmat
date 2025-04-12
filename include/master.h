#ifndef MASTER_H
#define MASTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <openssl/sha.h>
#include <cjson/cJSON.h>
#include <time.h>

void get_password(char *password, size_t size);
void hash_password(const char *password, unsigned char *hash);
void store_password(const char *path, const unsigned char *hash);
int create_master_pass(const char *path);

#endif // MASTER_H
