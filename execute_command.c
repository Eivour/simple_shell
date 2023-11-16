#include "shell.h"


/**
 * execute_command - Execute the given command with the provided arguments.
 *
 * This function searches for the specified command in the directories
 * listed in the PATH environment variable and attempts to execute it.
 * If the command is found and executable, the execution is performed
 * using execve(). If the command is not found, an error message is
 * displayed, and the program exits with a failure status.
 *
 * @args: The arguments for the command.
 * @environ: The environment variables.
 */

void execute_command(char *args[], char *environ[]) {

    char *path = getenv("PATH"); 
    char *token;

    if (path == NULL) {
        perror("getenv error");
        exit(EXIT_FAILURE);
    }

    token = strtok(path, ":");

    while (token != NULL) {
        char executable[PATH_MAX_LEN];

        snprintf(executable, PATH_MAX_LEN, "%s/%s", token, args[0]);

      
        if (access(executable, X_OK) == 0) {

            execve(executable, args, environ);

           
            perror("execve error");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, ":"); 
    }

    vour_print("Command not found\n");
    exit(EXIT_FAILURE);
}