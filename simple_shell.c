#include "shell.h"

/**
 * execute_shell - Entry point for the vourshell program.
 *
 * Return: 0 on success, 1 on failure.
 */

int main() {
    char *command;
    char *args[MAX_ARGS];
    pid_t pid;

    extern char **environ;

    command = malloc(100);

    if (command == NULL) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    while (1) {

        vour_print("VOUR$ ");
        
        if (fgets(command, 100, stdin) == NULL) {
            vour_print("catch ya later, matey...\n");
            free(command);
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        tokenize_command(command, args);

        if (args[0] == NULL) {
            perror("Error tokenizing command");
            continue;
        }

        pid = fork();

        if (pid == -1) {
            perror("fork error");
            break;
        }

        if (pid == 0) {
            execute_command(args, environ);
            exit(EXIT_SUCCESS); 
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }
    free(command);
    return 0;  
}