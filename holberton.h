#ifndef _PRINTF_
#define _PRINTF_

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

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
	void (*f)(va_list, mods *, char **);
} spec;

int _printf(const char *str, ...);
void h_m(void (*f)(va_list, mods *, char **), mods *m, va_list inp, char **ind);
void get_mods(const char *format, mods *out, int *i);
void mods_init(mods *out);
int get_int(const char *format, int *i);
int _atoi(char *buffer);
int handle_flags(const char *format, mods *out, int k);
void _putchar(char c, char **index);
void printInteger(va_list input, mods *m, char **index);
void printUnsigned(va_list input, mods *m, char **index);
void printRot(va_list input, mods *m, char **index);
void printReverse(va_list input, mods *m, char **index);
void printChar(va_list input, mods *m, char **index);
void printString(va_list input, mods *m, char **index);
void printPercent(va_list input, mods *m, char **index);
void printBinary(va_list input, mods *m, char **index);
void printHex(va_list input, mods *m, char **index);
void printHex_upper(va_list input, mods *m, char **index);
void printOctal(va_list input, mods *m, char **index);
void printString_custom(va_list input, mods *m, char **index);
void printAddress(va_list input, mods *m, char **index);
void binary_recursion(unsigned int i, char **index);
void octal_recursion(unsigned int i, char **index);
void hex_recursion(unsigned long int i, char **index);
void hex_recursion_upper(unsigned int i, char **index);
void int_recursion(unsigned long int i, char **index);
void (*get_print_func(char c))(va_list, mods *, char **);

#endif /* _PRINTF_ */
