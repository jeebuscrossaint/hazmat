#include "hazmat.h"

const char *home;
char hazmat_dir[PATH_MAX];

int exists(const char *fname) {
        FILE *file;
        if ((file = fopen(fname, "r")))
        {
                fclose(file);
                return 1;
        }
        return 0;
}

void create_hazmat_file(const char *path) {
        FILE *file = fopen(path, "w");
        if (file) {
                fprintf(file, "{}\n");
                fclose(file);
        }
}

int hinit() {
        home = getenv("HOME");
        if (!home) {
                return -1; // Bro is homeless???
        }

        snprintf(hazmat_dir, sizeof(hazmat_dir), "%s/.local/share/hazmat", home);
        char path[PATH_MAX];
        snprintf(path, sizeof(path), "%s/hazmat.json", hazmat_dir);

        if (exists(path)) {
                return 0; // File exists
        } else {
                mkdir(hazmat_dir, 0700);
                create_hazmat_file(path);
                create_master_pass(path);
        }

        return 0;
}