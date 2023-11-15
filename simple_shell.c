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
	ssize_t numstr;
	
	(void)argcount;
	(void)argvalue;

	while (true)
	{
		vour_print("%s", message);
		numstr = getline(&lineprinter, &count, stdin);
		
		if (numstr == -1)
		{
			vour_print("Error found, matey! Bye!\n");
			return (-1);
		}
		
		vour_print("%s\n", lineprinter);
		
		free(lineprinter);
	}
	return (0);
}
