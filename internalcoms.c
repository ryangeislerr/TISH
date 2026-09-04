// internalcoms.c
#include <string.h>
#include "internalcoms.h"

//command name and function
struct InternalEntry {
    const char *name;
    int (*fn)(int argc, char **argv);
};

//table of the internal commands 
static struct InternalEntry table[] = {
    {"help",     cmd_help},
    {"exit",     cmd_exit},
    {"tishtime", cmd_tishtime},
    {"lines",    cmd_lines},
    {"lastcom",  cmd_lastcom},
    {"pagesize", cmd_pagesize},
    {"maxprocesses", cmd_maxprocesses},
};

//checks if name matches any internal command
int is_internal(const char *name) {
    for (unsigned i = 0; i < sizeof(table)/sizeof(table[0]); ++i) {
        if (strcmp(name, table[i].name) == 0) return 1;
    }
    return 0;
}

// find and run the internal command
int run_internal(int argc, char **argv) {
    for (unsigned i = 0; i < sizeof(table)/sizeof(table[0]); ++i) {
        if (strcmp(argv[0], table[i].name) == 0) {
            return table[i].fn(argc, argv);
        }
    }

    return 1;
}
