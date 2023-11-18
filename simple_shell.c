#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *command;

    while (1)
    {
        display_prompt();
        command = read_user_input();

        if (!command)
            break;

        if (strcmp(command, "/bin/ls\n") == 0)
            execute_command("/bin/ls");
        else
            execute_command(command);

        free(command);
    }

    return 0;
}