// help.c
#include <stdio.h>
#include "internalcoms.h"

int cmd_help(int argc, char **argv) {
    (void)argc; (void)argv;
    puts("Internal commands:");
    puts("help -- prints out a helpful how-to");
    puts("exit -- exits the shell");
    puts("tishtime -- print out how long the shell has been running");
    puts("lines -- how many lines have been entered by the user");
    puts("lastcom -- execute the last command again");
    puts("maxprocesses -- maximum number of child processes");
    puts("pagesize -- system page size");
    return 0;
}
