#include "holberton.h"

void printInteger(va_list input, char **index)
{
	int out = va_arg(input, int);
	if (out < 0)
	{
		_putchar('-', index);
		int_recursion(out, index, -1);
	}
	else
		int_recursion(out, index, 1);
}

void int_recursion(int i, char **index, int negative)
{
	int digit;

	if (i == 0)
		return;
	digit = i % 10 * negative;
	int_recursion(i / 10, index, negative);
	_putchar(digit + 48, index);
}
