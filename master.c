#include "hazmat.h"

int create_master_pass(const char *path) 
{
        printf("We need to create you a master password.\n");
        printf("The password must adhere to the following rules:\n\n");
        printf("1. Verifiers and CSPs SHALL require passwords to be a minimum of eight characters in length and SHOULD require passwords to be a minimum of 15 characters in length.\n");
        printf("2. Verifiers and CSPs SHOULD permit a maximum password length of at least 64 characters.\n");
        printf("3. Verifiers and CSPs SHOULD accept all printing ASCII characters and the space character in passwords.\n");
        printf("4. Verifiers and CSPs SHOULD accept Unicode characters in passwords. Each Unicode code point SHALL be counted as a single character when evaluating password length.\n");
        printf("5. Verifiers and CSPs SHALL NOT impose other composition rules (e.g., requiring mixtures of different character types) for passwords.\n");
        printf("6. Verifiers and CSPs SHALL NOT require users to change passwords periodically. However, verifiers SHALL force a change if there is evidence of compromise of the authenticator.\n");
        printf("7. Verifiers and CSPs SHALL NOT permit the subscriber to store a hint that is accessible to an unauthenticated claimant.\n");
        printf("8. Verifiers and CSPs SHALL NOT prompt subscribers to use knowledge-based authentication (KBA) (e.g., “What was the name of your first pet?”) or security questions when choosing passwords.\n");
        printf("9. Verifiers SHALL verify the entire submitted password (i.e., not truncate it).\n\n");

        printf("            Do you consent to these guidlines? [Y/N]");
        char consent;
        scanf(" %c", &consent);
        if (consent == 'n' || consent == 'N') {
            return -1;
        }
        if (consent == 'Y' || consent == 'y') {
                // do the shit of getting a master pass n whatnot
                return 0;
        }


    return -1;
}