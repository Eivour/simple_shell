#include "shell.h"
/**
 * tokenize_input - Tokenize the user input into an array of arguments
 * @input: The user input string
 * Return: An array of arguments
 */
char **tokenize_input(char *input)
{
    size_t bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        handle_error();
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \t\n\r\a");
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                handle_error();
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\n\r\a");
    }
    tokens[position] = NULL;
    return tokens;
}