#include "holberton.h"

void printHex_upper(va_list input, char **index)
{
	unsigned int out = va_arg(input, unsigned int);

	if (out == 0)
	{
		_putchar(out + 48, index);
		return;
	}
	hex_recursion_upper(out, index);
}

void hex_recursion_upper(unsigned int i, char **index)
{
	unsigned int remainder;

	if (i == 0)
		return;
	remainder = i % 16;
	hex_recursion_upper(i / 16, index);
	if (remainder > 9)
		remainder += 7;
	_putchar(remainder + 48, index);
}