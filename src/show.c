#include "show.h"
#include "hazmat.h"
#include "add.h"  // For verify_master_password function

// Helper function to read and parse the entries JSON file
cJSON* read_entries_file() {
    // Get the HOME environment variable
    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        printf("Error: HOME environment variable not set.\n");
        return NULL;
    }

    // Construct path to entries file
    char entries_path[PATH_MAX];
    snprintf(entries_path, sizeof(entries_path), "%s/.hazmat/entries.json", home_dir);

    // Open and read the entries file
    FILE* file = fopen(entries_path, "r");
    if (!file) {
        printf("Error: Could not open entries file. No entries found.\n");
        return NULL;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (filesize == 0) {
        fclose(file);
        printf("Error: Entries file is empty.\n");
        return NULL;
    }

    // Read file content
    char* buffer = malloc(filesize + 1);
    if (!buffer) {
        fclose(file);
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    fread(buffer, 1, filesize, file);
    buffer[filesize] = '\0';
    fclose(file);

    // Parse JSON
    cJSON* root = cJSON_Parse(buffer);
    free(buffer);

    if (!root) {
        printf("Error: Invalid entries file format.\n");
        return NULL;
    }

    return root;
}

// Helper function to create a masked version of sensitive data
char* create_masked_string(const char* original) {
    if (!original || strlen(original) == 0) {
        return strdup("");
    }

    size_t len = strlen(original);
    char* masked = malloc(len + 1);
    if (!masked) {
        return NULL;
    }

    // Show first and last character, mask the rest with '*'
    if (len <= 2) {
        strcpy(masked, original);
    } else {
        masked[0] = original[0];
        for (size_t i = 1; i < len - 1; i++) {
            masked[i] = '*';
        }
        masked[len - 1] = original[len - 1];
        masked[len] = '\0';
    }

    return masked;
}

// Function to display an entry with timeout
void display_entry(cJSON* entry_obj, int timeout_seconds) {
    const char* username = cJSON_GetObjectItem(entry_obj, "username")->valuestring;
    const char* password = cJSON_GetObjectItem(entry_obj, "password")->valuestring;
    const char* url = cJSON_GetObjectItem(entry_obj, "url")->valuestring;
    const char* description = cJSON_GetObjectItem(entry_obj, "description")->valuestring;
    const char* notes = cJSON_GetObjectItem(entry_obj, "notes")->valuestring;
    const char* creation_time = cJSON_GetObjectItem(entry_obj, "creation_time")->valuestring;
    const char* last_modified = cJSON_GetObjectItem(entry_obj, "last_modified")->valuestring;

    // Create masked version of password
    char* masked_password = create_masked_string(password);

    // Display entry information
    printf("\n--- Entry Details ---\n");
    printf("Username: %s\n", username);
    printf("Password: %s (masked)\n", masked_password);
    printf("URL: %s\n", url);
    printf("Description: %s\n", description);
    printf("Notes: %s\n", notes);
    printf("Created: %s\n", creation_time);
    printf("Modified: %s\n", last_modified);
    printf("\n");

    // Ask if user wants to see the password
    printf("Show actual password? (y/n): ");
    char response;
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
        printf("Password: %s\n", password);
        printf("\nPassword will be hidden in %d seconds...\n", timeout_seconds);
        sleep(timeout_seconds);
        printf("\033[2J\033[H"); // Clear screen
        printf("Password hidden for security.\n");
    }

    free(masked_password);
}

// Function to show a specific password entry
int show_entry(const char* entry_name) {
    // First verify the master password
    if (!verify_master_password()) {
        return 0;
    }

    // Read entries file
    cJSON* root = read_entries_file();
    if (!root) {
        return 0;
    }

    // Find the requested entry
    cJSON* entry_obj = cJSON_GetObjectItem(root, entry_name);
    if (!entry_obj) {
        printf("Error: Entry '%s' not found.\n", entry_name);
        cJSON_Delete(root);
        return 0;
    }

    // Display the entry with a 5-second timeout for the password
    display_entry(entry_obj, 5);

    cJSON_Delete(root);
    return 1;
}

// Function to list all available entries
int list_entries() {
    // First verify the master password
    if (!verify_master_password()) {
        return 0;
    }

    // Read entries file
    cJSON* root = read_entries_file();
    if (!root) {
        return 0;
    }

    // Count entries
    int count = 0;
    cJSON* entry;
    cJSON_ArrayForEach(entry, root) {
        count++;
    }

    if (count == 0) {
        printf("No entries found.\n");
        cJSON_Delete(root);
        return 0;
    }

    // Display entries
    printf("\nFound %d entries:\n", count);
    printf("-------------------\n");

    cJSON_ArrayForEach(entry, root) {
        const char* name = entry->string;
        cJSON* url_obj = cJSON_GetObjectItem(entry, "url");
        const char* url = url_obj ? url_obj->valuestring : "";

        printf("- %s", name);
        if (strlen(url) > 0) {
            printf(" (%s)", url);
        }
        printf("\n");
    }
    printf("\n");

    cJSON_Delete(root);
    return 1;
}
