#ifndef ADD_H
#define ADD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <cjson/cJSON.h>

// Define a struct to hold password entry data
typedef struct {
    char* name;           // Name/title of the entry
    char* username;       // Username for the entry
    char* password;       // Password for the entry
    char* url;            // URL for the entry
    char* description;    // Description of the entry
    char* notes;          // Additional notes
    char* creation_time;  // When the entry was created
    char* last_modified;  // When the entry was last modified
} PasswordEntry;

// Function to add a new password entry
int add_entry(const char* entry_name);

// Helper functions for password entry fields
void get_input(const char* prompt, char* buffer, size_t size);
void get_single_line_input(const char* prompt, char* buffer, size_t size);
void get_password_input(char* password, size_t size);
void get_notes(char* notes, size_t size);
char* get_current_time();

// Function to verify master password
int verify_master_password();

// Function to save entries to the password store
int save_entry(PasswordEntry* entry);

#endif // ADD_H
