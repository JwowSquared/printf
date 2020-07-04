#ifndef _PRINTF_
#define _PRINTF_

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct specifier
{
	char *key;
	void (*f)(va_list, char **);
} spec;

int _printf(const char *str, ...);
void _putchar(char c, char **index);
void printInteger(va_list input, char **index);
void int_recursion(unsigned int i, char **index);
void printChar(va_list input, char **index);
void printString(va_list input, char **index);
void printPercent(va_list input, char **index);
void printBinary(va_list input, char **index);
void binary_recursion(unsigned int i, char **index);
void (*get_print_func(char c))(va_list, char **);

#endif /* _PRINTF_ */
