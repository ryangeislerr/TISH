#ifndef FLAGS_H
#define FLAGS_H

//prints the messages for the flags
// -h -- how to call tish
// -l -- list internal commands with a brief description
// -i -- takes the next item in as an internal command, runs it, then exits
int handle_flags(int argc, char **argv);

#endif //FLAGS_H