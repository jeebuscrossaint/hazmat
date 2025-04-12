#ifndef UPDATE_H
#define UPDATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>
#include <limits.h>
#include <time.h>

// Function to update a specific password entry
int update_entry(const char* entry_name);

// Helper function to display update menu and get user choice
int display_update_menu();

#endif // UPDATE_H
