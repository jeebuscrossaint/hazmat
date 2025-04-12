#include "hazmat.h"
#include "add.h"
#include "show.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        hhelp();
        return 0;
    }

    if (strcmp(argv[1], "help") == 0) {
        hhelp();
    } else if (strcmp(argv[1], "init") == 0) {
        hinit();
    }
    else if (strcmp(argv[1], "gen") == 0) {
        if (argc != 3) {
            fprintf(stderr, "Error: 'gen' command requires length argument\n");
            fprintf(stderr, "Usage: %s gen <length>\n", argv[0]);
            return 1;
        }
        // Convert string argument to integer
        int len = atoi(argv[2]);
        if (len < 8 || len > 64) {
            fprintf(stderr, "Error: length must be between 8 and 64\n");
            return 1;
        }
        if (len <= 0) {
            fprintf(stderr, "Error: length must be a positive number\n");
            return 1;
        }

        char* random_string = genrand(len);
        if (random_string == NULL) {
            fprintf(stderr, "Error: Failed to generate random number string\n");
            return 1;
        }

        printf("%s\n", random_string);
        free(random_string); // im not leaking bud
    }
    else if (strcmp(argv[1], "shred") == 0) {
        hshred();
    } else if (strcmp(argv[1], "add") == 0) {
        if (argc != 3) {
            fprintf(stderr, "Error: 'add' command requires entry name argument\n");
            fprintf(stderr, "Usage: %s add <entry-name>\n", argv[0]);
            return 1;
        }
        return add_entry(argv[2]) ? 0 : 1;
    } else if (strcmp(argv[1], "show") == 0) {
        if (argc == 2) {
            // With no arguments, list all entries
            return list_entries() ? 0 : 1;
        } else if (argc == 3) {
            // With one argument, show specific entry
            return show_entry(argv[2]) ? 0 : 1;
        } else {
            fprintf(stderr, "Error: Too many arguments for 'show' command\n");
            fprintf(stderr, "Usage: %s show [entry-name]\n", argv[0]);
            return 1;
        }
    } else if (strcmp(argv[1], "delete") == 0 && argc == 3) {
        // Implement delete functionality with argv[2] as the file
    } else if (strcmp(argv[1], "import") == 0 && argc == 3) {
        // Implement import functionality with argv[2] as the file
    } else if (strcmp(argv[1], "export") == 0 && argc == 3) {
        // Implement export functionality with argv[2] as the file
    } else {
        fprintf(stderr, "Error: Unrecognized or incomplete command.\n");
        hhelp();
        return 1;
    }

    return 0;
}
