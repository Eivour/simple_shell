#include "shell.h"

/**
 * vour_print - Custom printf using write system call
 * @format: Format specifier string
 * @...: Variable arguments
 */
void vour_print(const char *format, ...)
{
	va_list args;
	char buffer[MAX_LINE];

	va_start(args, format);

	vsnprintf(buffer, MAX_LINE, format, args);

	write(STDOUT_FILENO, buffer, strlen(buffer));
	va_end(args);
}
