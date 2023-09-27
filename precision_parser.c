#include "main.h"
#include "precision_parser_test.c"

/**
 * precision_parser - Extracts the precision specifier from the format string
 * @format: The format string
 * @index: A pointer to the current position in the format string.
 *
 * Return: The precision specifier (an integer), or -1 if not present.
 */

int precision_parser(const char *format, int *index)
{
	int pos = *index;
	int precision = -1;

	if (format[pos] == '.')
	{
		pos++;
		if (format[pos] >= '0' && format[pos] <= '9')
		{
			precision = 0;
			while (format[pos] >= '0' && format[pos] <= '9')
			{
				precision = precision * 10 + (format[pos] - '0');
				pos++;
			}
		}
		else 
		{
			precision = 0;
		}
	}

	*index = pos;
	return (precision);
}
