#include "shell.h"
/**
 * execute_command - Execute a command using execve
 * @command: The command to be executed
 * @args: The arguments for the command
 */

void execute_command(char *command, char **args)
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
        if (execve(command, args, NULL) == -1)
            handle_error();
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(child_pid, &status, 0);
    }
}