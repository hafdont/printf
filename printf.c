#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _write_char - writes a character to the standard output
 * @c: The character to write
 * @char_count: pointer that holds the character count
 */

void _write_char(char c, int *char_count)
{
	write(1, &c, 1);
	(*char_count)++;
}

/**
 * _write_str - Write a string to the standard output
 * @s: The string to be written
 * @char_count: Pointer that holds the character count
 */

void _write_str(char *s, int *char_count)
{
	if (s != NULL)
	{
		write(1, s, strlen(s));
		(*char_count) += strlen(s);
	}
	else
	{
		char *null_str = "(null)";

		write(1, null_str, strlen(null_str));
		(*char_count) += strlen(null_str);
	}
}

/**
 * _printf - printf function
 * @format: THe string that specifies thr format
 * Return: The number strings printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int char_count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_write_char(*format, &char_count);
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				_write_char(c, &char_count);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				_write_str(s, &char_count);
			}
			else if (*format == '%')
			{
				_write_char('%', &char_count);
			}
			else
			{
				_write_str((char *)(format - 1), &char_count);
			}
		}
		format++;
	}
	va_end(args);

	return (char_count);
}
