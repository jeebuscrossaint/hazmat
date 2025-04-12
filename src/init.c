#include "init.h"
#include "hazmat.h"
#include <sys/stat.h>  // For mkdir

const char *home;
char hazmat_dir[PATH_MAX];

int exists(const char *fname) {
    FILE *file;
    if ((file = fopen(fname, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

int hinit() {
    home = getenv("HOME");
    if (!home) {
        return -1; // Bro is homeless???
    }

    // Use a local buffer to reduce the number of snprintf calls
    char local_hazmat_dir[PATH_MAX];
    snprintf(local_hazmat_dir, sizeof(local_hazmat_dir), "%s/.hazmat", home);
    strncpy(hazmat_dir, local_hazmat_dir, sizeof(hazmat_dir));

    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/hazmat.json", local_hazmat_dir);

    if (exists(path)) {
        return 0; // File exists
    } else {
        mkdir(local_hazmat_dir, 0700);
        if (create_master_pass(path) != 0) {
            printf("Failed to create master password. Initialization aborted.\n");
            return -1;
        }
    }

    return 0;
}
