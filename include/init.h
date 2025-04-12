#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <limits.h>

extern const char *home;
extern char hazmat_dir[PATH_MAX];

int exists(const char *fname);
int hinit();

#endif // INIT_H
