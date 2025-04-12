#include "delete.h"
#include "hazmat.h"
#include "add.h"  // For verify_master_password
#include "show.h" // For read_entries_file

// Helper function to save the updated entries
int save_entries_file(cJSON* root) {
    // Get the HOME environment variable
    const char *home_dir = getenv("HOME");
    if (!home_dir) {
        printf("Error: HOME environment variable not set.\n");
        return 0;
    }

    // Construct path to entries file
    char entries_path[PATH_MAX];
    snprintf(entries_path, sizeof(entries_path), "%s/.hazmat/entries.json", home_dir);

    // Write updated JSON to file
    char* json_string = cJSON_Print(root);
    if (!json_string) {
        printf("Error: Failed to generate JSON string.\n");
        return 0;
    }

    FILE* file = fopen(entries_path, "w");
    if (!file) {
        printf("Error: Could not open entries file for writing.\n");
        free(json_string);
        return 0;
    }

    fprintf(file, "%s\n", json_string);
    fclose(file);
    free(json_string);

    return 1;
}

// Function to delete a specific password entry
int delete_entry(const char* entry_name) {
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

    // Ask for confirmation
    printf("Are you sure you want to delete entry '%s'? (y/n): ", entry_name);
    char response;
    scanf(" %c", &response);

    if (response != 'y' && response != 'Y') {
        printf("Delete operation canceled.\n");
        cJSON_Delete(root);
        return 0;
    }

    // Delete the entry
    cJSON_DeleteItemFromObject(root, entry_name);

    // Save the updated entries file
    if (!save_entries_file(root)) {
        printf("Error: Failed to save updated entries file.\n");
        cJSON_Delete(root);
        return 0;
    }

    printf("Entry '%s' successfully deleted.\n", entry_name);
    cJSON_Delete(root);
    return 1;
}
