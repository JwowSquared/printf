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

	return (total + address_recursion(addr, index));
}

int address_recursion(unsigned long int i, char **index)
{
        int total = 0;
        unsigned long int remainder;

        if (i == 0)
                return (0);
        remainder = i % 16;
        total += address_recursion(i / 16, index);
        if (remainder > 9)
                remainder += 39;
        return (total + _putchar(remainder + 48, index));
}
