#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c 
 * @c: The characters to print in the 1024 buffer
 * Return:  1 on success ,-ve number on error
 */

int _putchar(char c)
{
	static char buffer[1024];

	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buffer, i);

		i = 0;

	}
	if (c != -1)
	{
		buffer[i] = c;

		i++;
	}
	return (1);
}

/**
 * _puts - prints a string to stdout
 * @str: the string to print
 * Return: number of characters written
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
}
