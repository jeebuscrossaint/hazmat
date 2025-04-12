#ifndef SHRED_H
#define SHRED_H

#include <limits.h>
#include <stdio.h>
#include <dirent.h>

int is_directory_empty(const char *dirname);
int hshred();

#endif // SHRED_H
