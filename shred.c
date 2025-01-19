#include "hazmat.h"

int is_directory_empty(const char *dirname) {
    int n = 0;
    struct dirent *d;
    DIR *dir = opendir(dirname);
    if (dir == NULL) // Directory does not exist
        return 1;
    while ((d = readdir(dir)) != NULL) {
        if (++n > 2) // Directory is not empty
            break;
    }
    closedir(dir);
    return n <= 2; // Return true if directory is empty
}

int hshred() {
    int shred_avail = system("which shred > /dev/null");

    if (shred_avail != 0) {
        printf("Binary program 'shred' not found. OS Error code: %d \n", shred_avail);  /* rather use shred in a shell command from coreutils */
        return -1;                                                                              /*  since an in house solution is less defensible */
    }

    if (shred_avail == 0) {
        if (is_directory_empty("~/.local/share/hazmat")) {
            printf("Directory is empty or does not exist. Nothing to shred.\n");
            return 0;
        }

        printf("Beginning shred...\n");
        popen("shred -u -z -n 7 ~/.local/share/hazmat/*", "r");
        rmdir("~/.local/share/hazmat");
        printf("Shred complete. Good luck. \n");
        return 0;
    }

    printf("Some wild unhandled error occurred, or you somehow ran this program on Windows despite it using Linux specific headers and GNU coreutils.");
    return -1;
}