#include "main.h"

#define MAX_BUFFER_SIZE 1024



/**
 * memory_releaser - Flushes the buffer when full
 * @buffer: The character buffer
 * @buff_ind: a pointer to the buffer index
 */

void memory_releaser(char buffer[], int *buff_ind)
{
	if (*buff_ind == MAX_BUFFER_SIZE)
	{
		write(1, buffer, &buff_ind);
		*buff_ind = 0;
	}
}


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

	if (format == NULL)
		return (-10);

	va_start(args, format);
	
	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			buffer[buff_ind++] = *format;
			memory_releaser(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			memory_releaser(buffer, &buff_ind);
			format++;
			flags = get_flags(format);
			width = width_parser(format);
			precision = precision_parser(format);
			size = get_size(format);
			format++;
			printed_chars = handle_print(format, args, buffer,flags,width,precision,size);
			if (printed_chars == -1)
				return (-1);
		}
	}

	memory_releaser(buffer, &buff_ind);

	va_end(args);

	return (printed_chars);
}
