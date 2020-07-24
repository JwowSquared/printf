#ifndef _PRINTF_
#define _PRINTF_

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * struct modifiers - mods for formatting
 * @zero: 0 flag
 * @plus: + flag
 * @pound: # flag
 * @minus: - flag
 * @width: width formatting
 * @precision: precision formatting
 * @length: length formatting
 * @key: format specifier to print
 * Description: holds info on specific modifiers
 */
typedef struct modifiers
{
	int eos;
	int space;
	int zero;
	int plus;
	int pound;
	int minus;
	int width;
	int precision;
	char length;
	char key;
} mods;

/**
 * struct specifier - matches key with function
 * @key: format
 * @f: function
 */
typedef struct specifier
{
	char *key;

	int (*f)(va_list, mods *, char **);
} spec;

int _printf(const char *str, ...);
int h_m(int (*f)(va_list, mods *, char **), mods *m, va_list inp, char **ind);
void get_mods(const char *format, mods *out, int *i);
void mods_init(mods *out);
int get_int(const char *format, int *i);
int _atoi(char *buffer);
int handle_flags(const char *format, mods *out, int k);
int _putchar(char c, char **index);
int printInteger(va_list input, mods *m, char **index);
int printUnsigned(va_list input, mods *m, char **index);
int printRot(va_list input, mods *m, char **index);
int printReverse(va_list input, mods *m, char **index);
int printChar(va_list input, mods *m, char **index);
int printString(va_list input, mods *m, char **index);
int printPercent(va_list input, mods *m, char **index);
int printBinary(va_list input, mods *m, char **index);
int printHex(va_list input, mods *m, char **index);
int printHex_upper(va_list input, mods *m, char **index);
int printOctal(va_list input, mods *m, char **index);
int printString_custom(va_list input, mods *m, char **index);
int printAddress(va_list input, mods *m, char **index);
int binary_recursion(unsigned int i, char **index);
int octal_recursion(unsigned long int i, char **index);
int hex_recursion(unsigned int i, char **index);
int hex_recursion_upper(unsigned int i, char **index);
int int_recursion(unsigned long int i, char **index);
int address_recursion(unsigned long int i, char **index);
int (*get_print_func(char c))(va_list, mods *, char **);

#endif /* _PRINTF_ */
