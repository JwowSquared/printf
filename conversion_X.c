#include "holberton.h"

/**
 * printHex_upper - prints a number in hex in cap letters
 * @input: arugment to handle
 * @m: modifiers
 * @index: buffer
 * Return: no return
 */
int printHex_upper(va_list input, mods *m, char **index)
{
	int total = 0;
	unsigned long int out;

	if (m->length == 'l')
		out = va_arg(input, unsigned long int);
	else
		out = va_arg(input, unsigned int);

	if (out == 0)
		return (total + _putchar(out + 48, index));
	else if (m->pound)
	{
		total += _putchar('0', index);
		total += _putchar('X', index);
	}
	return (total + hex_recursion_upper(out, index));
}

/**
 * hex_recursion_upper - converts and prints a number into hex
 * @i: number passed
 * @index: buffer
 * Return: no return
 */
int hex_recursion_upper(unsigned long int i, char **index)
{
	int total = 0;
	unsigned long int remainder;

	if (i == 0)
		return (0);
	remainder = i % 16;
	total += hex_recursion_upper(i / 16, index);
	if (remainder > 9)
		remainder += 7;
	return (total + _putchar(remainder + 48, index));
}
