#include "master.h"
#include "hazmat.h"

void get_password(char *password, size_t size) {
    struct termios oldt, newt;
    int i = 0;
    char c;

    // Turn off echo
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read password
    while (i < size - 1 && (c = getchar()) != '\n' && c != EOF) {
        password[i++] = c;
        printf("*");
        fflush(stdout); // Ensure the asterisk is printed immediately
    }
    password[i] = '\0';

    // Turn echo back on
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\n");
}

void hash_password(const char *password, unsigned char *hash) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
}

void store_password(const char *path, const unsigned char *hash) {
    // Create root object
    cJSON *root = cJSON_CreateObject();

    // Add master password hash
    char hash_string[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash_string + (i * 2), "%02x", hash[i]);
    }
    cJSON_AddStringToObject(root, "master_password", hash_string);

    // Add settings object
    cJSON *settings = cJSON_CreateObject();
    cJSON_AddNumberToObject(settings, "safe_time", 300); // 5 minutes in seconds
    cJSON_AddItemToObject(root, "settings", settings);

    // Add timestamps
    time_t now = time(NULL);
    char time_str[32];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));
    cJSON_AddStringToObject(root, "creation_time", time_str);
    cJSON_AddStringToObject(root, "last_modified", time_str);

    // Write to file
    char *json_string = cJSON_Print(root);
    FILE *file = fopen(path, "w");
    if (file) {
        fprintf(file, "%s\n", json_string);
        fclose(file);
    }

    cJSON_Delete(root);
    free(json_string);
}

int create_master_pass(const char *path) {
        printf("We need to create you a master password.\n");
        printf("The password must adhere to the following rules:\n\n");
        printf("1. Verifiers and CSPs SHALL require passwords to be a minimum of eight characters in length and SHOULD require passwords to be a minimum of 15 characters in length.\n");
        printf("2. Verifiers and CSPs SHOULD permit a maximum password length of at least 64 characters.\n");
        printf("3. Verifiers and CSPs SHOULD accept all printing ASCII characters and the space character in passwords.\n");
        printf("4. Verifiers and CSPs SHOULD accept Unicode characters in passwords. Each Unicode code point SHALL be counted as a single character when evaluating password length.\n");
        printf("5. Verifiers and CSPs SHALL NOT impose other composition rules (e.g., requiring mixtures of different character types) for passwords.\n");
        printf("6. Verifiers and CSPs SHALL NOT require users to change passwords periodically. However, verifiers SHALL force a change if there is evidence of compromise of the authenticator.\n");
        printf("7. Verifiers and CSPs SHALL NOT permit the subscriber to store a hint that is accessible to an unauthenticated claimant.\n");
        printf("8. Verifiers and CSPs SHALL NOT prompt subscribers to use knowledge-based authentication (KBA) (e.g., \"What was the name of your first pet?\") or security questions when choosing passwords.\n");
        printf("9. Verifiers SHALL verify the entire submitted password (i.e., not truncate it).\n\n");

        printf("Do you consent to these guidelines? [Y/N] ");
    char consent;
    scanf(" %c", &consent);
    while (getchar() != '\n'); // Consume the newline character

    if (consent == 'n' || consent == 'N') {
        return -1;
    }
    if (consent == 'Y' || consent == 'y') {
        char password[65];
        printf("Enter your master password: ");
        get_password(password, sizeof(password));

        // Check password length
        size_t len = strlen(password);
        if (len < 8 || len > 64) {
            printf("Password must be between 8 and 64 characters.\n");
            return -1;
        }

        unsigned char hash[SHA256_DIGEST_LENGTH];
        hash_password(password, hash);
        store_password(path, hash);  // Use the enhanced store_password function
        return 0;
    }

    return -1;
}
