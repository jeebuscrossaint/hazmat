#include "update.h"
#include "hazmat.h"
#include "add.h"  // For input functions
#include "show.h" // For read_entries_file
#include "delete.h" // For save_entries_file

// Helper function to display update menu and get user choice
int display_update_menu() {
    printf("\nWhat would you like to update?\n");
    printf("1. Username\n");
    printf("2. Password\n");
    printf("3. URL\n");
    printf("4. Description\n");
    printf("5. Notes\n");
    printf("0. Cancel\n");
    printf("Enter choice: ");

    int choice;
    scanf("%d", &choice);

    // Consume newline
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    return choice;
}

// Function to update a specific password entry
int update_entry(const char* entry_name) {
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

    // Get current values
    const char* current_username = cJSON_GetObjectItem(entry_obj, "username")->valuestring;
    const char* current_password = cJSON_GetObjectItem(entry_obj, "password")->valuestring;
    const char* current_url = cJSON_GetObjectItem(entry_obj, "url")->valuestring;
    const char* current_description = cJSON_GetObjectItem(entry_obj, "description")->valuestring;
    const char* current_notes = cJSON_GetObjectItem(entry_obj, "notes")->valuestring;

    // Display current values
    printf("\nCurrent values for entry '%s':\n", entry_name);
    printf("Username: %s\n", current_username);
    printf("Password: ****** (masked)\n");
    printf("URL: %s\n", current_url);
    printf("Description: %s\n", current_description);
    printf("Notes: %s\n", current_notes);

    // Display update menu
    int choice = display_update_menu();
    if (choice == 0) {
        printf("Update canceled.\n");
        cJSON_Delete(root);
        return 0;
    }

    char buffer[1024] = {0};

    switch (choice) {
        case 1: // Update username
            printf("Current username: %s\n", current_username);
            printf("Enter new username: ");
            if (fgets(buffer, sizeof(buffer), stdin)) {
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                cJSON_ReplaceItemInObject(entry_obj, "username", cJSON_CreateString(buffer));
                printf("Username updated.\n");
            }
            break;

        case 2: // Update password
            printf("Enter new password: ");
            get_password_input(buffer, sizeof(buffer));
            cJSON_ReplaceItemInObject(entry_obj, "password", cJSON_CreateString(buffer));
            printf("Password updated.\n");
            break;

        case 3: // Update URL
            printf("Current URL: %s\n", current_url);
            printf("Enter new URL: ");
            if (fgets(buffer, sizeof(buffer), stdin)) {
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                cJSON_ReplaceItemInObject(entry_obj, "url", cJSON_CreateString(buffer));
                printf("URL updated.\n");
            }
            break;

        case 4: // Update description
            printf("Current description: %s\n", current_description);
            printf("Enter new description: ");
            if (fgets(buffer, sizeof(buffer), stdin)) {
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                cJSON_ReplaceItemInObject(entry_obj, "description", cJSON_CreateString(buffer));
                printf("Description updated.\n");
            }
            break;

        case 5: // Update notes
            printf("Current notes: %s\n", current_notes);
            printf("Enter new notes (leave blank line to finish):\n");
            get_notes(buffer, sizeof(buffer));
            cJSON_ReplaceItemInObject(entry_obj, "notes", cJSON_CreateString(buffer));
            printf("Notes updated.\n");
            break;

        default:
            printf("Invalid choice.\n");
            cJSON_Delete(root);
            return 0;
    }

    // Update last modified timestamp
    time_t now = time(NULL);
    char time_str[32];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));
    cJSON_ReplaceItemInObject(entry_obj, "last_modified", cJSON_CreateString(time_str));

    // Save the updated entries file
    if (!save_entries_file(root)) {
        printf("Error: Failed to save updated entries file.\n");
        cJSON_Delete(root);
        return 0;
    }

    printf("Entry '%s' successfully updated.\n", entry_name);
    cJSON_Delete(root);
    return 1;
}
