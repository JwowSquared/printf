#include "holberton.h"

/**
 * printInteger - prints an integer
 * @input: arugments
 * @m: modifiers
 * @index: buffer
 * Return: no return
 */
void printInteger(va_list input, mods *m, char **index)
{
	unsigned long int out;
	short int s = 0;
	int i = 0;
	long int l = 0;

	if (m->length == 'l')
	{
		l = va_arg(input, long int);
		if (l < 0)
			out = l * -1;
		else
			out = l;
	}
	else if (m->length == 'h')
	{
		s = va_arg(input, int);
		if (s < 0)
			out = s * -1;
		else
			out = s;
	}
	else
	{
		i = va_arg(input, int);
		if (i < 0)
			out = i * -1;
		else
			out = i;
	}
	if (l < 0 || s < 0 || i < 0)
		_putchar('-', index);
	else if ((l > 0 || s > 0 || i > 0) && m->plus)
		_putchar('+', index);
	if (out == 0 && m->precision == 0)
		return;
	int_recursion(out, index);
}

/**
 * int_recursion - prints number passed to it
 * @i: number passed
 * @index: buffer
 * Return: no return
 */
void int_recursion(unsigned long int i, char **index)
{
	unsigned long int digit;

	if (i == 0)
		return;
	digit = i % 10;
	int_recursion(i / 10, index);
	_putchar(digit + 48, index);
}
