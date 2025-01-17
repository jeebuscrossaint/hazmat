#include "hazmat.h"

void print_help() {
	printf("Usage: hazmat [OPTIONS]\n");
	printf("Options:\n");
	printf("  help    help		   Display this help message and help for subcommands.\n");
	printf("  init    main		   Initialize a list/the program as a whole for usage.\n");
	printf("  shred         	   Shred data. EXTREMELEY DANGEROUS. More info in hazmat help shred or man hazmat\n");
	printf("  add	          	   Add an entry\n");
	printf("  delete  [1][12]     	   Delete a specific entry from a specific list or just a whole list\n");
	printf("  show    [2][248]     	   Show information about a specific entry in a specific list\n");
	printf("  import  FILE   	   Import data from FILE\n");
	printf("  export  FILE   	   Export data to FILE\n");
}

int main(int argc, char *argv[]) {

	if (argc < 2) {
		print_help();
		return 1;
	}

	if (strcmp(argv[1], "help") == 0) {
		print_help();
	} else if (strcmp(argv[1], "init") == 0) {
		hinit();
	}
	else if (strcmp(argv[1], "shred") == 0) {
		hshred();
	} else if (strcmp(argv[1], "add") == 0 && argc == 3) {
		// Implement add functionality with argv[2] as the file
	} else if (strcmp(argv[1], "delete") == 0 && argc == 3) {
		// Implement delete functionality with argv[2] as the file
	} else if (strcmp(argv[1], "show") == 0 && argc == 3) {
		// Implement show functionality with argv[2] as the file
	} else if (strcmp(argv[1], "import") == 0 && argc == 3) {
		// Implement import functionality with argv[2] as the file
	} else if (strcmp(argv[1], "export") == 0 && argc == 3) {
		// Implement export functionality with argv[2] as the file
	} else {
		fprintf(stderr, "Error: Unrecognized or incomplete command.\n");
		print_help();
		return 1;
	}

	return 0;
}
