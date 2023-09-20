#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - custome printf function
 * @format: the format string
 * Return: The no of charster printed out
 */

int _printf( const char *format, ...)
{
	va_list args;
	int char_count = 0;

	va_start(args, format);

	while(*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_count++;
		}
		else 
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				char_count++;
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				char_count++;
			}
		}
		format++;
	}
	va_end(args);

	return char_count;
}
