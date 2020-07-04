#include "holberton.h"

int printInteger(va_list input)
{
	int out = va_arg(input, int);
	return (int_recursion(out));
}

int int_recursion(int i)
{
	int digit, total;

	if (i == 0)
		return (0);
	digit = i % 10;
	total = 1 + int_recursion(i / 10);
	_putchar(digit + 48);
	return (total);
}
