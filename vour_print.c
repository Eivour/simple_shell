#include <stdarg.h>
#include "shell.h"

/**
 * vour_print - custom print function
 * @format: format string
 */
void vour_print(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'd':
				printf("%d", va_arg(args, int));
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				break;
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 's':
				printf("%s", va_arg(args, char *));
				break;
			default:
				putchar(*format);
				break;
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}

	va_end(args);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int integer_var = 10;
	float float_var = 3.14;
	char char_var = 'A';
	char string_var[] = "Hello, world!";

	vour_print("Integer: %d\n", integer_var);
	vour_print("Float: %f\n", float_var);
	vour_print("Character: %c\n", char_var);
	vour_print("String: %s\n", string_var);

	return (0);
}
