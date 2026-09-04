//max processes
#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>
#include "internalcoms.h"

int cmd_maxprocesses(int argc, char **argv){
    (void)argc; 
    (void)argv;

    //if the call to sysconf is not successful then it will return -1
    // and errno is set properly
    errno = 0;                         
    long max_process = sysconf(_SC_CHILD_MAX);
    if (max_process == -1) {
        if (errno != 0) {
            //error from sysconf
            perror("sysconf(_SC_CHILD_MAX)");
            return 1;
        } else {
            fprintf(stderr, "tish: max processes are not supported on this system\n");
            return 1;
        }
    }

    printf("%ld\n", max_process);   
    return 0;
}