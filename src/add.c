#include "add.h"
#include "hazmat.h"
#include "master.h"
#include <termios.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>

// Function to get input with a prompt
void get_input(const char* prompt, char* buffer, size_t size) {
    printf("%s: ", prompt);

    // Clear input buffer
    fflush(stdin);

    // Get the input
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove newline if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
    }
}

void get_single_line_input(const char* prompt, char* buffer, size_t size) {
    get_input(prompt, buffer, size);
}

void get_password_input(char* password, size_t size) {
    printf("Password: ");
    get_password(password, size); // Use the existing get_password function from master.c
}

// Function to get username input
void get_username(char* username, size_t size) {
    get_input("Username", username, size);
}

// Function to get URL input
void get_url(char* url, size_t size) {
    get_input("URL", url, size);
}

// Function to get description input
void get_description(char* description, size_t size) {
    get_input("Description", description, size);
}

// Function to get notes input
void get_notes(char* notes, size_t size) {
    printf("Notes (leave blank line to finish): \n");

    // Clear input buffer
    fflush(stdin);

    notes[0] = '\0'; // Initialize to empty string
    size_t total = 0;
    char line[256];

    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        // Check for blank line (just a newline)
        if (line[0] == '\n') {
            break;
        }

        size_t line_len = strlen(line);
        if (total + line_len < size) {
            strcat(notes + total, line);
            total += line_len;
        } else {
            printf("Note too long, truncated.\n");
            break;
        }
    }
}

// Generate current time string
char* get_current_time() {
    time_t now = time(NULL);
    char* time_str = malloc(32);
    if (time_str) {
        strftime(time_str, 32, "%Y-%m-%d %H:%M:%S", localtime(&now));
    }
    return time_str;
}

// Function to verify the master password
int verify_master_password() {
    // Get the HOME environment variable directly
    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        printf("Error: HOME environment variable not set.\n");
        return 0;
    }

    // Construct the path to the master file
    char master_path[PATH_MAX];
    snprintf(master_path, sizeof(master_path), "%s/.hazmat/hazmat.json", home_dir);

    // Read the master file
    FILE* file = fopen(master_path, "r");
    if (!file) {
        printf("Error: Could not open master file at %s. Run 'hazmat init' first.\n", master_path);
        return 0;
    }

    // Rest of the function remains the same...

    // Get file size
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read the file content
    char* buffer = malloc(filesize + 1);
    if (!buffer) {
        fclose(file);
        printf("Error: Memory allocation failed.\n");
        return 0;
    }

    fread(buffer, 1, filesize, file);
    buffer[filesize] = '\0';
    fclose(file);

    // Parse JSON
    cJSON* root = cJSON_Parse(buffer);
    free(buffer);

    if (!root) {
        printf("Error: Invalid master file format.\n");
        return 0;
    }

    // Get stored hash - use standard cJSON function
    cJSON* master_hash = cJSON_GetObjectItem(root, "master_password");
    if (!master_hash || !cJSON_IsString(master_hash)) {
        cJSON_Delete(root);
        printf("Error: Master password not found in config.\n");
        return 0;
    }

    const char* stored_hash = master_hash->valuestring;

    // Get user input
    char password[65];
    printf("Enter your master password: ");
    get_password(password, sizeof(password));

    // Hash the input
    unsigned char hash[SHA256_DIGEST_LENGTH];
    hash_password(password, hash);

    // Convert hash to hex string for comparison
    char hash_string[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hash_string + (i * 2), "%02x", hash[i]);
    }

    // Compare hashes
    int result = strcmp(hash_string, stored_hash) == 0;
    if (!result) {
        printf("Error: Incorrect master password.\n");
    }

    cJSON_Delete(root);
    return result;
}

// Also update the save_entry function:

int save_entry(PasswordEntry* entry) {
    // Get the HOME environment variable directly
    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        printf("Error: HOME environment variable not set.\n");
        return 0;
    }

    // Construct the path to the entries file
    char entries_path[PATH_MAX];
    snprintf(entries_path, sizeof(entries_path), "%s/.hazmat/entries.json", home_dir);

    // Rest of the function remains the same...

    // Read existing entries file or create a new one
    cJSON* root = NULL;
    FILE* file = fopen(entries_path, "r");

    if (file) {
        // File exists, read it
        fseek(file, 0, SEEK_END);
        long filesize = ftell(file);
        fseek(file, 0, SEEK_SET);

        char* buffer = malloc(filesize + 1);
        if (!buffer) {
            fclose(file);
            printf("Error: Memory allocation failed.\n");
            return 0;
        }

        fread(buffer, 1, filesize, file);
        buffer[filesize] = '\0';
        fclose(file);

        root = cJSON_Parse(buffer);
        free(buffer);

        if (!root) {
            root = cJSON_CreateObject();
        }
    } else {
        // File doesn't exist, create a new JSON object
        root = cJSON_CreateObject();
    }

    // Check if entry name already exists - use standard cJSON function
    if (cJSON_GetObjectItem(root, entry->name)) {
        printf("Error: An entry with name '%s' already exists.\n", entry->name);
        cJSON_Delete(root);
        return 0;
    }

    // Create entry object
    cJSON* entry_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(entry_obj, "username", entry->username);
    cJSON_AddStringToObject(entry_obj, "password", entry->password);
    cJSON_AddStringToObject(entry_obj, "url", entry->url);
    cJSON_AddStringToObject(entry_obj, "description", entry->description);
    cJSON_AddStringToObject(entry_obj, "notes", entry->notes);
    cJSON_AddStringToObject(entry_obj, "creation_time", entry->creation_time);
    cJSON_AddStringToObject(entry_obj, "last_modified", entry->last_modified);

    // Add entry to root
    cJSON_AddItemToObject(root, entry->name, entry_obj);

    // Write to file
    char* json_string = cJSON_Print(root);
    file = fopen(entries_path, "w");
    if (!file) {
        printf("Error: Could not open entries file for writing.\n");
        cJSON_Delete(root);
        free(json_string);
        return 0;
    }

    fprintf(file, "%s\n", json_string);
    fclose(file);

    cJSON_Delete(root);
    free(json_string);

    printf("Entry '%s' added successfully.\n", entry->name);
    return 1;
}


// Main function to add a new password entry
int add_entry(const char* entry_name) {
    // First verify the master password
    if (!verify_master_password()) {
        return 0;
    }

    // Initialize entry structure
    PasswordEntry entry;

    // Allocate memory and set the entry name
    entry.name = strdup(entry_name);

    // Get entry information from user
    char username[100] = {0};
    char password[100] = {0};
    char url[256] = {0};
    char description[256] = {0};
    char notes[1024] = {0};

    get_single_line_input("Username", username, sizeof(username));
    get_password_input(password, sizeof(password));
    get_single_line_input("URL", url, sizeof(url));
    get_single_line_input("Description", description, sizeof(description));
    get_notes(notes, sizeof(notes));

    // Allocate and copy the strings
    entry.username = strdup(username);
    entry.password = strdup(password);
    entry.url = strdup(url);
    entry.description = strdup(description);
    entry.notes = strdup(notes);

    // Set creation and modification times
    entry.creation_time = get_current_time();
    entry.last_modified = strdup(entry.creation_time);

    // Save the entry
    int result = save_entry(&entry);

    // Free allocated memory
    free(entry.name);
    free(entry.username);
    free(entry.password);
    free(entry.url);
    free(entry.description);
    free(entry.notes);
    free(entry.creation_time);
    free(entry.last_modified);

    return result;
}
