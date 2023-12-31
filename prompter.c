#include "shell.h"

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
    write(STDOUT_FILENO, "vourshell$ ", 11);
}

/**
 * read_user_input - Read user input from the command line
 *
 * Return: The user input as a string
 */
char *read_user_input(void)
{
    size_t bufsize = 0;
    char *buffer = NULL;

    if (getline(&buffer, &bufsize, stdin) == -1)
        return NULL;

    return buffer;
}