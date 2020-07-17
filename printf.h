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

int _putchar(char c);
int printInteger(va_list input);
int int_recursion(int i);
int printChar(va_list input);
int printString(va_list input);
int printBinary(va_list input);
int binary_recursion(unsigned int i);

#endif /* _PRINTF_ */