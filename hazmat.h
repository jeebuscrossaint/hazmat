#ifndef HAZMAT_H
#define HAZMAT_H

/* libc headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <unistd.h>
#include <linux/limits.h>

extern const char *home;
extern char hazmat_dir[PATH_MAX];

/* init.c */
int hinit();

/* shred.c */
int hshred();

/* master.c */
int create_master_pass(const char *path);

#endif // HAZMAT_H