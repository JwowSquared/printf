#include "printf.h"

int printBinary(va_list input)
{
	unsigned int out = va_arg(input, unsigned int);
	if (out == 0)
	{
		_putchar(out + 48);
		return (1);
	}
	return (binary_recursion(out));
}

int binary_recursion(unsigned int i)
{
	int remainder, total;

	if (i == 0)
		return (0);

	remainder = i % 2;
	total = 1 + binary_recursion(i / 2);
	_putchar(remainder + 48);
	return (total);
}
