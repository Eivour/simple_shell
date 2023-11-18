#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *command;
    char **args;

    while (1)
    {
        display_prompt();
        command = read_user_input();

        if (!command)
            break;

        args = tokenize_input(command);
        execute_command(args[0], args);

        free(command);
        free(args);
    }

    return 0;
}