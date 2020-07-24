#include "holberton.h"

/**
 * printAddress - prints an address
 * @input: arugment to handle
 * @index: buffer
 * @m: modifiers
 * Return: no return
 */
int printAddress(va_list input, mods *m, char **index)
{
	int total = 0;
	unsigned long int addr = va_arg(input, unsigned long int);

	(void)m;

	if (addr == 0)
	{
		total += _putchar('(', index);
		total += _putchar('n', index);
		total += _putchar('i', index);
		total += _putchar('l', index);
		return (total += _putchar(')', index));
	}

	total += _putchar('0', index);
	total += _putchar('x', index);

	return (total + hex_recursion(addr, index));
}
