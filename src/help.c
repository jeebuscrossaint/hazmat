#include "help.h"
#include "hazmat.h"

void hhelp() {
	printf("=============================================\n");
	printf("=  hazmat: the best project on the resume   =\n");
	printf("=					    =\n");
	printf("=		  v0.0.9		    =\n");
	printf("=					    =\n");
	printf("= 	     Amarnath S. Patel	 	    =\n");
	printf("=					    =\n");
	printf("= https://github.com/jeebuscrossaint/hazmat =\n");
	printf("=============================================\n\n");
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
