#include "holberton.h"

void printBinary(va_list input, char **index)
{
	unsigned int out = va_arg(input, unsigned int);

	if (out == 0)
	{
		_putchar(out + 48, index);
		return;
	}
	binary_recursion(out, index);
}

void binary_recursion(unsigned int i, char **index)
{
	unsigned int remainder;

	if (i == 0)
		return;

	remainder = i % 2;
	binary_recursion(i / 2, index);
	_putchar(remainder + 48, index);
}
