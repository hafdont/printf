#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int width_parser(const char *format, int *index, va_list args)
{
	int pos = *index;
	int width = -1;

	if (format[pos] == '%')
	{
		pos++;

		if (format[pos] == '*')
		{
			width = va_arg(args, int);
		}
		else if (format[pos] >= '0' && format[pos] <= '9')
		{
			width = 0;
			while (format[pos] >= '0' && format[pos] <= '9')
			{
				width = width * 10 + (format[pos] - '0');
				pos++;
			}
		}
	}

	*index = pos;

	return (width);
}
