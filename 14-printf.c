#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * rot13_char - Applies ROT13 encoding to a character.
 * @c: The character to be encoded.
 *
 * Return: The ROT13 encoded character.
 */
char rot13_char(char c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (((c - 'A' + 13) % 26) + 'A');	/* Apply ROT13 to uppercase letters */
	else if ((c >= 'a' && c <= 'z'))
		return (((c - 'a' + 13) % 26) + 'a');	/* Apply ROT13 to lowercase letters */

	return (c);	/* Return unchanged for non-alphabetical characters */
}

/**
 * my_printf - Custom printf-like function to handle the "R" specifier.
 * @format: The format string.
 * @...: Additional arguments.
 *
 * Return: The number of characters printed.
 */
int my_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int result = 0;	/* Track the number of characters printed */

	for (size_t i = 0; i < strlen(format); i++)
	{
		if (format[i] == '%' && format[i + 1] == 'R')
		{
			i++;	/* Skip the 'R' specifier */
			char *str = va_arg(args, char *);	/* Get the string argument */

			if (str != NULL)
			{
				/* Apply ROT13 encoding and print the result */
				for (size_t j = 0; str[j] != '\0'; j++)
				{
					char encoded = rot13_char(str[j]);

					putchar(encoded);

					result++;
				}
			}
		}
		else
		{
			putchar(format[i]);	/* Print characters other than 'R' */
			result++;
		}
	}

	va_end(args);
	return (result);	/* Return the number of characters printed */
}
