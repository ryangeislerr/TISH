// internalcoms.h
// declarations for internal commands
#ifndef INTERNALCOMS_H
#define INTERNALCOMS_H

//prints out a help list for all the internal commands available
int cmd_help(int argc, char **argv);

//exits the shell
int cmd_exit(int argc, char **argv);

//outputs how long the shell has been running
int cmd_tishtime(int argc, char **argv);

//how many non empty lines have been entered by the user
int cmd_lines(int argc, char **argv);

//executes the last command again
int cmd_lastcom(int argc, char **argv);

//displays the system page size
int cmd_pagesize(int agrc, char **argv);

// maximum number of child processes
int cmd_maxprocesses(int argc, char **argv);

// return nonzero if name matches an internal command
int is_internal(const char *name);

// call the matching internal command
int run_internal(int argc, char **argv);

// tell the current working directory of the indicated process
int cmd_cwd(int argc, char **argv);

#endif //INTERNALCOMS_H
