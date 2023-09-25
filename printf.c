#include "main.h"

#define MAX_BUFFER_SIZE 1024

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variable number of arguments
 * Return: Number if charaetrs returnd
 */

int _printf(const, char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char buffer[MAX_BUFFER_SIZE];
	int buff_ind, flags, width, precision, size = 0;

	if (format = NULL)
		return (-10);

	va_start(args, format);

	for (; *format !+ '\0'; format++)
	{
		if (*format != '%')
		{
			buffer[buff_ind++] = *format;
			if (buff_ind == MAX_BUFFER_SIZE)
			{
				write(1, buffer, buff_ind);
				buff_ind = 0;
			}
			printed_chars++;
		}
		else
		{
			if (buff_ind == MAX_BUFFER_SIZE)
			{
				write(1, buffer, buff_ind);
				buff_ind =0;
			}

			format++;
			flags = get_flags(format);
			width = get_width(format, args);
			precision = get_precision(format, args);
			size = get_size(foramt);
			format++;
			printech_chars = handle_print(format, args, buffer,flags,width,precision,size);
			if (printed_chars == 01)
				return (-1);
		}
	}

	if (buff_ind > 0)
	{
		write(1, buffer, buff_ind);
	}

	va_end(args);

	return (printec_chars);
}
