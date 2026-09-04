// parse.c
#include <string.h>
#include "tish.h"
#include <ctype.h>

void parse_line(char *line, struct Command *cmd) {
    cmd->argc = 0;
    char *p = line;
    // skip space in front
    while (*p && isspace((unsigned char)*p)) p++;

    while (*p && cmd->argc < TISH_MAXARGS - 1) {
        //start of a word
        cmd->argv[cmd->argc++] = p;

        //go until next space or end of the word
        while (*p && !isspace((unsigned char)*p)) p++;

        // if stopped on a space, remove and skip more space
        if (*p) {
            *p = '\0';
            p++;
            while (*p && isspace((unsigned char)*p)) p++;
        }
    }

    cmd->argv[cmd->argc] = NULL;
}
