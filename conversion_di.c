#include "holberton.h"

/**
 * printInteger - prints an integer
 * @input: arugment to handle
 * @m: modifiers
 * @index: buffer
 * Return: no return
 */
int printInteger(va_list input, mods *m, char **index)
{
	unsigned long int out;
	int total = 0;
	long int i = 0;

	if (m->length == 'l')
	{
		i = va_arg(input, long int);
		if (i < 0)
			out = i * -1;
		else
			out = i;
	}
	else
	{
		i = va_arg(input, int);
		if (i < 0)
			out = i * -1;
		else
			out = i;
	}

	if (i < 0)
		total += _putchar('-', index);
	else if (i > 0 && m->plus)
		total += _putchar('+', index);
	if (out == 0 && m->precision == 0)
		return (0);
	else if (out == 0)
		return (total + _putchar('0', index));

	return (total + int_recursion(out, index));
}

/**
 * int_recursion - prints number passed to it
 * @i: number passed
 * @index: buffer
 * Return: no return
 */
int int_recursion(unsigned long int i, char **index)
{
	int total = 0;
	unsigned long int digit;

	if (i == 0)
		return (0);
	digit = i % 10;
	total += int_recursion(i / 10, index);
	return (total + _putchar(digit + 48, index));
}
