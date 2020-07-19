#include "holberton.h"

void printInteger(va_list input, char **index)
{
	unsigned int out;
	int in = va_arg(input, int);

	if (in < 0)
	{
		_putchar('-', index);
		out = in * -1;
	}
	else
		out = in;

	int_recursion(out, index);
}

void int_recursion(unsigned int i, char **index)
{
	unsigned int digit;

	if (i == 0)
		return;
	digit = i % 10;
	int_recursion(i / 10, index);
	_putchar(digit + 48, index);
}
