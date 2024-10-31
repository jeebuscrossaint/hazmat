#ifndef TYPES_HH
#define TYPES_HH

// first layer of flags, simple checking of if one was given or not, if it exists, or if the flag is asking for help

typedef enum {
    FLAG_GIVEN, // if a flag is given
    FLAG_NOT_GIVEN, // if a flag is not given (we will probably abort the program)
    FLAG_DNE, // if a flag does not exist
    FLAG_HELP, // if the flag is a help 
    FLAG_EXISTS // if the flag is real then continue with other ish
} FlagStatus;

// second layer of flags more specific, if we are adding an item, deleting an item, updating an item, showing an item, or asking for help (hints ig)

typedef enum {
    FLAG_ADD // if we are adding an item
    , FLAG_DELETE // if we are deleting an item
    , FLAG_UPDATE // if we are updating an item
    , FLAG_SHOW // if we are showing an item
    , FLAG_HINT // if we are asking for help
} Flag;

typedef enum {
    
} Idk;

#endif //TYPES_HH