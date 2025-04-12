#include "help.h"
#include "hazmat.h"

void hhelp() {
    printf("=============================================\n");
    printf("=  hazmat: the best project on the resume   =\n");
    printf("=                                           =\n");
    printf("=                v0.0.9                     =\n");
    printf("=                                           =\n");
    printf("=          Amarnath S. Patel                =\n");
    printf("=                                           =\n");
    printf("= https://github.com/jeebuscrossaint/hazmat =\n");
    printf("=============================================\n\n");
    printf("Usage: hazmat [OPTIONS]\n");
    printf("Options:\n");
    printf("  help              Display this help message and help for subcommands.\n");
    printf("  init              Initialize a list/the program as a whole for usage.\n");
    printf("  add <entry-name>  Add a new password entry with the specified name.\n");
    printf("  show [entry]      List all entries or show details for a specific entry.\n");
    printf("  update <entry>    Update an existing password entry.\n");
    printf("  delete <entry>    Delete a specific entry from the password store.\n");
    printf("  gen <length>      Generate a random password of specified length.\n");
    printf("  shred             Shred data. EXTREMELY DANGEROUS. More info in hazmat help shred or man hazmat.\n");
    printf("  import <file>     Import data from FILE.\n");
    printf("  export <file>     Export data to FILE.\n");
}
