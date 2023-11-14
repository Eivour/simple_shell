#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

void vour_print(const char *format, ...);
void show_prompt(void);
void make_things_happen(const char *format);

#endif
