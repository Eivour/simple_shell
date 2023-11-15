#include "shell.h"

/**
 * vour_print - Custom printf using write system call
 * @format: Format specifier string
 * @...: Variable arguments
 */
void vour_print(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	char buffer[MAX_LINE];

	vsnprintf(buffer, MAX_LINE, format, args);

	write(STDOUT_FILENO, buffer, strlen(buffer));
	va_end(args);
}
