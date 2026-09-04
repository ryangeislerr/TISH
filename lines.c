// lines.c
#include <stdio.h>
#include "tish.h"
#include "internalcoms.h"

int cmd_lines(int argc, char **argv) {
    (void)argc; (void)argv;
    unsigned long n = tish_get_line_count();
    printf("%lu\n", n);
    return 0;
}

