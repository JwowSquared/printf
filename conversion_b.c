#include "holberton.h"
/**
 * printBinary - Prints a number in binary
 * @input: arguments
 * @index: character buffer
 * @m: modifiers
 * Return: 1023 if buffer flush
 */
int printBinary(va_list input, mods *m, char **index)
{
	unsigned int out = va_arg(input, unsigned int);
	(void)m;

	if (out == 0)
		return (_putchar(out + 48, index));
	return (binary_recursion(out, index));
}

/**
 * binary_recursion - Takes number and prints binary conversion
 * @i: number to print
 * @index: buffer
 * Return: no return
 */
int binary_recursion(unsigned int i, char **index)
{
	unsigned int remainder;
	int total = 0;

	if (i == 0)
		return (0);

	remainder = i % 2;
	total += binary_recursion(i / 2, index);
	return (total + _putchar(remainder + 48, index));
}
