#ifndef _PRINTF_
#define _PRINTF_

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct specifier - binds keys and functions
 * @key: format specifier
 * @f: function
 * Description: Stores specifiers and their function
 */
typedef struct specifier
{
	char *key;
	void (*f)(va_list, char **);
} spec;

int _printf(const char *str, ...);
void _putchar(char c, char **index);
void printInteger(va_list input, char **index);
void printUnsigned(va_list input, char **index);
void int_recursion(unsigned int i, char **index);
void printRot(va_list input, char **index);
void printReverse(va_list input, char **index);
void printChar(va_list input, char **index);
void printString(va_list input, char **index);
void printPercent(va_list input, char **index);
void printBinary(va_list input, char **index);
void printHex(va_list input, char **index);
void printHex_upper(va_list input, char **index);
void printOctal(va_list input, char **index);
void binary_recursion(unsigned int i, char **index);
void octal_recursion(unsigned int i, char **index);
void hex_recursion(unsigned long int i, char **index);
void hex_recursion_upper(unsigned int i, char **index);
void printString_custom(va_list input, char **index);
void printAddress(va_list input, char **index);
void (*get_print_func(char c))(va_list, char **);

#endif /* _PRINTF_ */
