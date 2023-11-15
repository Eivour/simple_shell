#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

void vour_print(const char *format, ...);
ssize_t get_input(char **line, size_t *count);
char **tokenize_input(char *line, const char *delimiter);
void free_tokens(char **tokens);

#endif