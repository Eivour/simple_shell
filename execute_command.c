#include "shell.h"
/**
 * execute_command - Execute a command using execve
 * @command: The command to be executed
 */
void execute_command(char *command)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        handle_error();
        return;
    }

    if (child_pid == 0)
    {
        char **args = malloc(2 * sizeof(char *));
        if (!args)
        {
            handle_error();
            exit(EXIT_FAILURE);
        }

        args[0] = command;
        args[1] = NULL;

        if (execve(command, args, NULL) == -1)
            handle_error();

        free(args);
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(child_pid, &status, 0);
    }
}