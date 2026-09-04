// lastcom.c
#include <stdio.h>
#include <string.h>
#include "tish.h"
#include "internalcoms.h"

int cmd_lastcom(int argc, char **argv) {
    (void)argc; (void)argv;

    //get the previosuly stored command
    const char *last = tish_get_last_command();

    if (!last || last[0] == '\0') {
        fprintf(stderr, "tish: no last command to repeat\n");
        return 1;
    }
    //if the last saved command was in fact last command
    if (strcmp(last, "lastcom") == 0) {
        fprintf(stderr, "tish: last command was 'lastcom' (nothing to repeat)\n");
        return 1;
    }

    // make a writable copy that isn't touched by parse_line
    char buf[TISH_MAXLINE + 1]; 
    size_t i = 0;
    while (i < TISH_MAXLINE && last[i] != '\0') {
        buf[i] = last[i];
        i++;
    }
    buf[i] = '\0';      

    //parse the line into a command
    struct Command cmd = (struct Command){0};
    parse_line(buf, &cmd);
    if (cmd.argc == 0) return 0;

    if (is_internal(cmd.argv[0])) {
        return run_internal(cmd.argc, cmd.argv);
    } else {
        fprintf(stderr, "tish: not an internal command: %s\n", cmd.argv[0]);
        return 1;
    }
}
