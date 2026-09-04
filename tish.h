// tish.h
#ifndef TISH_H
#define TISH_H
#include <stddef.h>

#define TISH_MAXARGS 10 // max number of words we keep from one input line
#define TISH_MAXLINE 100 // max characters to read for one input line

struct Command {
    int   argc; // number of words found
    char *argv[TISH_MAXARGS];// pointer to those words the last being null
};

//parsing the commands
void parse_line(char *line, struct Command *cmd);

// record the time when the shell starts
void tish_record_start_time(void);

// return how long the shell has been running
double tish_uptime_seconds(void);

// increment and read the how many non-empty lines were entered
void tish_increment_line_count(void);
unsigned long tish_get_line_count(void);

// save and retrieve the last command
void tish_set_last_command(const char *line);
const char* tish_get_last_command(void);

#endif //TISH_H
