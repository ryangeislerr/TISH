// tishtime.c
#include <stdio.h>
#include "tish.h"
#include "internalcoms.h"

int cmd_tishtime(int argc, char **argv) {
    (void)argc; (void)argv;
    double secs = tish_uptime_seconds();   
    printf("%.0f seconds\n", secs);       
    return 0;
}
