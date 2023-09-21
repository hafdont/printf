#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
/*flags*/
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/*Convert an unsigned long integer to a hexadecimal string.*/
char *convert_to_hex(unsigned long int n);

/*putchar function*/

int _putchar(char c);

/*string function*/
int _puts(char *str);

/* function that produces output according to a format*/
int _printf(const char *format, ...);

/*Handle the following conversion specifiers*/
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/*prints address of input in hexa form*/
int print_address(va_list l, flags_t *f);

/* Handle the following conversion specifier: p.*/
int print_pointer(va_list args, flags_t *flags);


#endif
