#include "shell.h"
/**
 * main - code starts here
 * @argcount: argument counter
 * @argvalue: argument value
 * Return: Always 0 (success)
 */
int main(int argcount, char **argvalue)
{
	char *message = "(fj_shell#) ";
	char *lineprinter;
	size_t count = 0;

	vour_print("%s", message);
	getline(&lineprinter, &count, stdin);

	free(lineprinter);
	return (0);
}
