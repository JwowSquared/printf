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
	short int s;
	int i;
	long int l;

	if (m->length == 'l')
	{
		l = va_arg(input, long int);
		if (l < 0)
		{
			_putchar('-', index);
			out = l * -1;
		}
		else
		{
			if (l > 0 && m->plus)
				_putchar('+', index);
			out = l;
		}
	}
	else if (m->length == 'h')
	{
		s = va_arg(input, int);
		if (s < 0)
		{
			_putchar('-', index);
			out = s * -1;
		}
		else
		{
			if (s > 0 && m->plus)
				_putchar('+', index);
			out = s;
		}
	}
	else 
	{
		i = va_arg(input, int);
		if (i < 0)
		{
			_putchar('-', index);
			out = i * -1;
		}
		else
		{
			if (i > 0 && m->plus)
				_putchar('+', index);
			out = i;
		}
	}

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
