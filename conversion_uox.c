#include "holberton.h"

void printUnsigned(va_list input, char **index)
{
	unsigned int out = va_arg(input, unsigned int);

	int_recursion(out, index);
}

void printOctal(va_list input, char **index)
{
	unsigned int out = va_arg(input, unsigned int);

	if (out == 0)
	{
		_putchar(out + 48, index);
		return;
	}
	octal_recursion(out, index);
}

void octal_recursion(unsigned int i, char **index)
{
	unsigned int remainder;

	if (i == 0)
		return;

	remainder = i % 8;
	octal_recursion(i / 8, index);
	_putchar(remainder + 48, index);
}

void printHex(va_list input, char **index)
{
	unsigned int out = va_arg(input, unsigned int);

	if (out == 0)
	{
		_putchar(out + 48, index);
		return;
	}
	hex_recursion(out, index);
}

void hex_recursion(unsigned int i, char **index)
{
	unsigned int remainder;

	if (i == 0)
		return;
	remainder = i % 16;
	hex_recursion(i / 16, index);
	if (remainder > 9)
		remainder += 39;
	_putchar(remainder + 48, index);
}
