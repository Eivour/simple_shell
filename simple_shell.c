#include "shell.h"

/**
 * main - Entry point for the simple shell program
 * @argcount: Number of command-line arguments
 * @argvalue: Array of command-line argument strings
 * Return: 0 on success
 */
int main(int argcount, char **argvalue)
{
    char *message = "(fj_shell#) ";
    char *lineprinter = NULL;
    size_t count = 0;
    ssize_t numstr;
    const char *delimiter = " \n";
    char **tokens = NULL;
    char *tokenizer;
    int token_count = 0;
    int i;

    (void)argcount;
    (void)argvalue;

    while (1)
    {
        vour_print("%s", message);
        numstr = getline(&lineprinter, &count, stdin);

        if (numstr == -1)
        {
            vour_print("Error found, matey! Bye!\n");
            free(lineprinter);
            return -1;
        }

        vour_print("%s\n", lineprinter);

        tokenizer = strtok(lineprinter, delimiter);
        while (tokenizer != NULL)
        {
            token_count++;
            tokenizer = strtok(NULL, delimiter);
        }

        tokens = (char **)malloc((token_count + 1) * sizeof(char *));

        if (tokens == NULL)
        {
            perror("malloc error");
            free(lineprinter);
            return -1;
        }

        tokenizer = strtok(lineprinter, delimiter);
        for (i = 0; tokenizer != NULL; i++)
        {
            tokens[i] = strdup(tokenizer);
            vour_print("%s\n", tokens[i]);
            tokenizer = strtok(NULL, delimiter);
        }

        tokens[i] = NULL;

        for (i = 0; i < token_count; i++)
        {
            free(tokens[i]);
        }

        free(tokens);
        token_count = 0;
    }

    return 0;
}