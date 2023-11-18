#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>


#define MAX_LINE 1024
#define MAX_ARGS 64
#define true 1
#define PATH_MAX_LEN 1024


void vour_print(const char *format, ...);
void tokenize_command(char *command, char *args[]);
void display_prompt(void);
char *read_user_input(void);
void execute_command(char *command);
void handle_error(void);

#endif