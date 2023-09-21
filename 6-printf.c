#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

/**
 * print_pointer - Prints a pointer's address (p) in hexadecimal format.
 * @args: va_list arguments from _printf
 * @flags: Pointer to flags (unused in this example)
 *
 * Return: Number of characters printed
 */

int print_pointer(va_list args, flags_t *flags)
{
	char *str;
	unsigned long int pointer = va_arg(args, unsigned long int);

	int count = 0;

	(void)flags;

	if (!pointer)
		return (_puts("(nil)"));

	str = convert_to_hex(pointer);
	count += _puts("0x");
	count += _puts(str);

	return (count);
}

