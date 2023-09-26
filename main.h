#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
/*flags*/
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;



#define F_MINUS (1 << 0)
#define F_PLUS (1 << 1)
#define F_SPACE (1 << 2)
#define F_HASH (1 << 3)
#define F_ZERO (1 << 4)

/* get flags function*/
int get_flags(const char *format, int *index);

/*get size function*/
const char *get_size(const char *format, int *index);

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
