#ifndef HAZMAT_H
#define HAZMAT_H

/* libc headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Linux headers */
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <termios.h>
#include <dirent.h>
#include <sys/random.h>

/* Cryptograhpy */
#include <openssl/sha.h>

/* JSON */
#include <cjson/cJSON.h>

extern const char *home;
extern char hazmat_dir[PATH_MAX];

/* init.c */
int hinit();

/* shred.c */
int hshred();

/* master.c */
int create_master_pass(const char *path);

/* help.c */
void hhelp();

/* random.c */
char* genrand(int len);

#endif // HAZMAT_H
