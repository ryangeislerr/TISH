// exit_cmd.c
#include <stdlib.h>
#include "internalcoms.h"

int cmd_exit(int argc, char **argv) {
    (void)argc; (void)argv;
    exit(0);            
    return 0;    
}
