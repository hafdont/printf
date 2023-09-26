#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_size - Extracts the size of the specifier from the format string
 * @format: the format string
 * @index: the cuurent index of the format string i haev it as pos
 * Return: THe size specifier as a string
 */

const char *get_size(const char *format, int *index)
{
	int pos = *index;
	char *size_specifier = (char *)malloc(3 * sizeof(char));

	if (size_specifier == NULL)
	{
		return (NULL);
	}

	if (format[pos] == 'h' || format[pos] == 'l' ||	format[pos] == 'j' || format[pos] == 'z' || format[pos] == 't')
	{
		size_specifier[0] = format[pos];
		pos++;

		if ((format[pos] == 'h' || format[pos] == 'l') && size_specifier[0] != 'j')
		{
			size_specifier[1] = format[pos];
			pos++;
		}
	}

	*index = pos - 1;

	return (size_specifier);
}
