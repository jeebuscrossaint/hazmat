// hazmat/include/delete.h
#ifndef DELETE_H
#define DELETE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>
#include <limits.h>

// Function to delete a specific password entry
int delete_entry(const char* entry_name);

// Helper function to save the updated entries
int save_entries_file(cJSON* root);

#endif // DELETE_H
