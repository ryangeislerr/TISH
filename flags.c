#include <stdio.h>
#include <string.h>
#include "flags.h"
#include "internalcoms.h"

int handle_flags(int argc, char **argv) {
    if (argc <= 1) return 0; 
    const char *flag = argv[1];

    if (strcmp(flag, "-h") == 0) {
        puts("How to call tish: ./tish [-h] [-l] [-i internal command]");
        return 1; 
    }

    if (strcmp(flag, "-l") == 0) {
        puts("Internal commands:");
        puts("help -- prints out a helpful how-to");
        puts("exit -- exits the shell");
        puts("tishtime -- print out how long the shell has been running");
        puts("lines -- how many lines have been entered by the user");
        puts("lastcom -- execute the last command again");
        puts("maxprocesses -- maximum number of child processes");
        puts("pagesize -- system page size");
        return 1;
    }

    if (strcmp(flag, "-i") == 0) {
        if (argc < 2) {
            fprintf(stderr, "tish: -i requires an internal command name\n");
            return 1;
        }

        // argv[2] is the internal command 
        if (!is_internal(argv[2])) {
            fprintf(stderr, "tish: -i expects an internal command (%s)\n", argv[2]);
            return 1;
        }

        int ic_argc = argc;
        char **ic_argv = &argv[2];
        (void)run_internal(ic_argc, ic_argv);
        return 1; 
    }

    // unknown flag
    fprintf(stderr, "tish: unknown flag: %s\n", flag);
    return 1;
}
