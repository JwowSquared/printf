#include "holberton.h"
/**
 * printBinary - Prints a number in binary
 * @input: arguments
 * @index: character buffer
 * Return: no return
 */
void printBinary(va_list input, char **index)
{
	unsigned int out = va_arg(input, unsigned int);

	if (out == 0)
	{
		_putchar(out + 48, index);
		return;
	}
	binary_recursion(out, index);
}

/**
 * binary_recursion - Takes number and prints binary conversion
 * @i: number to print
 * @index: buffer
 * Return: no return
 */
void binary_recursion(unsigned int i, char **index)
{
	unsigned int remainder;

	if (i == 0)
		return;

	remainder = i % 2;
	binary_recursion(i / 2, index);
	_putchar(remainder + 48, index);
}
