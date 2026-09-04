// main.c
#include <stdio.h>    
#include <string.h>   
#include <stdlib.h>   
#include <time.h> 
#include <sys/types.h>
#include <unistd.h>
#include "tish.h"
#include "internalcoms.h"
#include "flags.h"

static time_t startTime = 0; // when the shell started
static unsigned long line_count = 0;// how many non empty lines the user entered
static char last_command[TISH_MAXLINE] = {0}; // the last non empty line typed


void tish_record_start_time(void) {
    startTime = time(NULL);
}

double tish_uptime_seconds(void) {
    time_t now = time(NULL);
    return (double)(now - startTime);
}

void tish_increment_line_count(void) {
    line_count++;
}

unsigned long tish_get_line_count(void) {
    return line_count;
}

void tish_set_last_command(const char *line) {
    if (!line) return;
    unsigned long i = 0;
    while (i < (unsigned long)(TISH_MAXLINE - 1) && line[i] != '\0') {
        last_command[i] = line[i];
        i++;
    }
    last_command[i] = '\0';
}

const char* tish_get_last_command(void) {
    return last_command;
}

//try and run external command if internal command is not found
static void run_external(struct Command *cmd){
    if(cmd->argc == 0 || cmd -> argv[0] == NULL) return;

    //forks a child process
    pid_t pid = fork();
    if (pid < 0){
        //error occured
        fprintf(stderr, "Fork Failed\n");
        return;
    
}   else if(pid ==0){
        //child process
        execvp(cmd->argv[0], cmd->argv);
        fprintf(stderr, "Execvp Failed\n");
        exit(1);

}   else {
        //parent will wait for child to complete
        wait(NULL);
    }
}

//prompt for the shell
static void prompt(void) {
    printf("tish> ");
    fflush(stdout);
}

/////////MAIN////////// 
int main(int argc, char **argv) {
    //  record when the shell started
    tish_record_start_time();

    if (handle_flags(argc,argv)){
        return 0;
    }

    char line[TISH_MAXLINE];

    //main loop
    while (1) {
        prompt();

        // read one line
        if (fgets(line, sizeof line, stdin) == NULL) {
            putchar('\n');
            break;           
        }

        // remove the newline to compare 
        unsigned long len = (unsigned long)strlen(line);
        if (len && line[len - 1] == '\n') 
            line[len - 1] = '\0';

        //ignore empty lines from user
        if (line[0] == '\0') continue;
        tish_increment_line_count();

        // make a copy before parsing takes place
        char line_copy[TISH_MAXLINE];
        unsigned long i = 0;
        while (i < (unsigned long)(TISH_MAXLINE - 1) && line[i] != '\0') {
            line_copy[i] = line[i];
            i++;
}
        line_copy[i] = '\0';

        // parse the line into a command
        struct Command cmd = {0};
        parse_line(line, &cmd);

        //if no words/enter
        if (cmd.argc == 0) continue;

        //if last command was lastcom
        if (strcmp(cmd.argv[0], "lastcom") != 0) {
            tish_set_last_command(line_copy);
        }

        if (is_internal(cmd.argv[0])) {
            (void)run_internal(cmd.argc, cmd.argv);
        } else {
            run_external(&cmd);
        }
    }

    return 0; 
}


