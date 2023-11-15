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
    char *lineprinter;
    size_t count = 0;
    ssize_t numstr;
    char **arg_tokens;

    (void)argvalue;
    (void)argcount;

    while (true)
    {
        vour_print("%s", message);
        numstr = get_input(&lineprinter, &count);

        if (numstr == -1)
        {
            vour_print("Error found, matey! Bye!\n");
            return -1;
        }

        vour_print("%s\n", lineprinter);

        arg_tokens = tokenize_input(lineprinter, " \n");

        free_tokens(arg_tokens);
        free(lineprinter);
    }
    return 0;
}