#include "shell.h"


/**
 * tokenize_command - Tokenizes the given command string into an array of arguments.
 *
 * This function takes a command string and breaks it into individual
 * arguments, storing them in the provided array. The strtok function is
 * used to tokenize the command based on space (' ') as the delimiter.
 *
 * @command: The command string to be tokenized.
 * @args: An array to store the tokenized arguments.
 */

 
void tokenize_command(char *command, char *args[]) {
    int i = 0;
    args[i] = strtok(command, " ");

    while (args[i] != NULL && i < MAX_ARGS - 1) {
        i++;
        args[i] = strtok(NULL, " ");
    }
    args[i + 1] = NULL;
}