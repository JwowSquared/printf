#include "holberton.h"

void printAddress(va_list input, char **index)
{
	unsigned long int addr = va_arg(input, unsigned long int);

	_putchar('0', index);
	_putchar('x', index);
	hex_recursion(addr, index);
}
