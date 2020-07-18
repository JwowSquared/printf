#include "holberton.h"

int printInteger(va_list input)
{
	int out = va_arg(input, int);
	unsigned int output;

	if (out < 0)
	{
		_putchar('-');
		out *= -1;
		output = out;
		return (int_recursion(output));
	}
	output = out;
	return (int_recursion(output));
}

int int_recursion(unsigned int i)
{
	unsigned int digit, total;

	if (i == 0)
		return (0);
	digit = i % 10;
	total = 1 + int_recursion(i / 10);
	_putchar(digit + 48);
	return (total);
}
