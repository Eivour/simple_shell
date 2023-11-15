#include "shell.h"

int main(int argcount, char **argvalue)
{
    char *message = "(fj_shell#) ";
    char *lineprinter;
    size_t count = 0;

    printf("%s", message);
    getline(&lineprinter, &count, stdin);

    free(lineprinter);
    return (0);
}