#include "hazmat.h"

int is_directory_empty(const char *dirname) {
        int n = 0;
        struct dirent *d;
        DIR *dir = opendir(dirname);
        if (dir == NULL) // Directory does not exist
            return 1;
        while ((d = readdir(dir)) != NULL) {
            if (strcmp(d->d_name, ".") != 0 && strcmp(d->d_name, "..") != 0) {
                n++; // Only count non-dot entries
            }
        }
        closedir(dir);
        return n == 0; // Return true if directory has no non-dot entries
    }

int hshred() {
    int shred_avail = system("which shred > /dev/null");

    if (shred_avail != 0) {
        printf("Binary program 'shred' not found. OS Error code: %d \n", shred_avail);
        return -1;
    }

    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        printf("HOME environment variable not set.\n");
        return -1;
    }

    char cmd[PATH_MAX + 50];
    snprintf(cmd, sizeof(cmd), "shred -u -z -n 7 %s/.hazmat/* 2>/dev/null", home_dir);
    system(cmd);
    
    snprintf(cmd, sizeof(cmd), "rmdir %s/.hazmat 2>/dev/null", home_dir);
    system(cmd);
    
    printf("\033[0;32mShred complete.\033[0m \033[0;31mGood luck.\033[0m\n");
    return 0;
}