#include "holberton.h"

/**
 * printUnsigned - Prints an unsigned int
 * @input: arugment to handle
 * @index: buffer
 * @m: modifiers
 * Return: no return
 */
int printUnsigned(va_list input, mods *m, char **index)
{
	unsigned long int out;

	if (m->length == 'l')
		out = va_arg(input, unsigned long int);
	else
		out = va_arg(input, unsigned int);

	if (out == 0)
	{
		if (m->precision == 0)
			return (0);
		else
			return (_putchar('0', index));
	}
	return (int_recursion(out, index));
}

/**
 * printOctal - prints a number in octal
 * @input: arugment to handle
 * @m: modifiers
 * @index: buffer
 * Return: no return
 */
int printOctal(va_list input, mods *m, char **index)
{
	int total = 0;
	unsigned long int out;

	if (m->length == 'l')
		out = va_arg(input, unsigned long int);
	else
		out = va_arg(input, unsigned int);

	if (out == 0)
	{
		if (m->precision == 0)
			return (0);
		else
			return (_putchar('0', index));
	}
	if (m->pound)
		total += _putchar('0', index)
;
	return (total + octal_recursion(out, index));
}

/**
 * octal_recursion - converts and prints a number passed to it in octal
 * @i: number passed
 * @index: buffer
 * Return: no return
 */
int octal_recursion(unsigned long int i, char **index)
{
	int total = 0;
	unsigned int remainder;

	if (i == 0)
		return (0);

	remainder = i % 8;
	total += octal_recursion(i / 8, index);
	return (total + _putchar(remainder + 48, index));
}

/**
 * printHex - prints a number in hex
 * @input: arugments
 * @index: buffer
 * @m: modifiers
 * Return: no return
 */
int printHex(va_list input, mods *m, char **index)
{
	int total = 0;
	unsigned long int out;

	if (m->length == 'l')
		out = va_arg(input, unsigned long int);
	else
		out = va_arg(input, unsigned int);

	if (out == 0)
	{
		if (m->precision == 0)
			return (0);
		else
			return (_putchar('0', index));
	}
	if (m->pound)
	{
		total += _putchar('0', index);
		total += _putchar('x', index);
	}

	return (total + hex_recursion(out, index));
}

/**
 * hex_recursion - converts and prints a number passed into hex
 * @i: number passed
 * @index: buffer
 * Return: no return
 */
int hex_recursion(unsigned long int i, char **index)
{
	int total = 0;
	unsigned long int remainder;

	if (i == 0)
		return (0);
	remainder = i % 16;
	total += hex_recursion(i / 16, index);
	if (remainder > 9)
		remainder += 39;
	return (total + _putchar(remainder + 48, index));
}
