#include "shell.h"
/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *command;

    while (true)
    {
        display_prompt();
        command = read_user_input();

        if (!command)
            break;

        execute_command(command);
        free(command);
    }

    return 0;
}