#include "main.h"

/**
 * get_flags - Calculate the active flags
 * @format: Formated string in which to print the arguments
 * @index: Pointer to the current index in the format string
 * Return: Flags
 */

int get_flags(const char *format, int *index)
{
	int pos = *index + 1;
	int flags = 0;
	const char FLAGS_chars[] = {'-', '\0', ' ', '#', '0', '+'};
	const int FLAGS_VALUES[] = {F_MINUS, 0, F_SPACE, F_HASH, F_ZERO, F_PLUS};
	int found;
	int f;

	for (; format[pos] != '\0'; pos++)
	{
		found = 0;

		for (f = 0; FLAGS_chars[f] != '\0'; f++)
		{
			if (format[pos] == FLAGS_chars[f])
			{
				flags |= FLAGS_VALUES[f];
				found = 1;
				break;
			}
		}

		if (!found)
		{
			break;
		}
	}

	*index = pos - *index - 1;

	return (flags);
}
