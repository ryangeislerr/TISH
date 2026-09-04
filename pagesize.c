//page size
#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>
#include "internalcoms.h"

int cmd_pagesize(int argc, char **argv) {
    (void)argc;
    (void)argv;

    //if the call to sysconf is not successful then it will return -1
    // and errno is set properly
    errno = 0;
    long page_size = sysconf(_SC_PAGE_SIZE);
    if (page_size == -1) {
        if (errno != 0) {
            // error from sysconf
            perror("sysconf(_SC_PAGESIZE)");
            return 1;
        } else {
            fprintf(stderr, "tish: page size is not supported on this system\n");
            return 1;
        }
    }

    printf("%ld\n", page_size);
    return 0;
}