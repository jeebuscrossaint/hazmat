#include "hazmat.h"

int hshred() {
        int shred_avail = system("which shred > /dev/null");
        
        if (shred_avail != 0) {
                printf("Binary program 'shred' not found. OS Error code: %d \n", shred_avail);  /* rather use shred in a shell command from coreutils */
                return -1;                                                                              /*  since an in house solution is less defensible */
        }

        if (shred_avail == 0) {
                printf("Beginning shred...\n");
                popen("shred -u -z -n 7 ~/.local/share/hazmat/*", "r");
                rmdir("~/.local/share/hazmat");
                printf("Shred complete. Good luck. \n");
                return 0;
        }

        printf("Some wild unhandled error occured, or you somehow ran this program on Windows despite it using Linux specific headers and GNU coreutils.");
        return -1;
}