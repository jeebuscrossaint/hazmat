#ifndef SHOW_H
#define SHOW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>
#include <limits.h>
#include <unistd.h>  // For sleep function

// Function to show a specific password entry
int show_entry(const char* entry_name);

// Function to list all available entries
int list_entries();

// Helper function to read and parse the entries JSON file
cJSON* read_entries_file();

// Helper function to mask portions of sensitive data
char* create_masked_string(const char* original);

// Function to display an entry with optional timeout
void display_entry(cJSON* entry_obj, int timeout_seconds);

#endif // SHOW_H
