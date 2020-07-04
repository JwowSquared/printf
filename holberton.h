#ifndef _PRINTF_
#define _PRINTF_

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct specifier
{
	char *key;
	int (*f)(va_list);
} spec;

int _printf(const char *str, ...);
int _putchar(char c);
int printInteger(va_list input);
int int_recursion(int i, int negative);
int printChar(va_list input);
int printString(va_list input);
int printPercent(va_list input);
int printBinary(va_list input);
int binary_recursion(unsigned int i);
int (*get_print_func(char c))(va_list);

#endif /* _PRINTF_ */
