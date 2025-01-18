#include "hazmat.h"

int main(int argc, char *argv[]) {

	if (argc < 2) {
		hhelp();
		return 1;
	}

	if (strcmp(argv[1], "help") == 0) {
		hhelp();
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
		hhelp();
		return 1;
	}

	return 0;
}
