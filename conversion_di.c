#include "holberton.h"

int printInteger(va_list input)
{
	int out = va_arg(input, int);
	if (out < 0)
	{
		_putchar('-');
		return (int_recursion(out, -1));
	}
	return (int_recursion(out, 1));
}

int int_recursion(int i, int negative)
{
	int digit, total;

	if (i == 0)
		return (0);
	digit = i % 10 * negative;
	total = 1 + int_recursion(i / 10, negative);
	_putchar(digit + 48);
	return (total);
}
