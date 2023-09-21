#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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


#endif
