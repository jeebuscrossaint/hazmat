#ifndef HAZMAT_H
#define HAZMAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

extern const char *home;
extern char hazmat_dir[PATH_MAX];

int hinit();
int hshred();


#endif // HAZMAT_H