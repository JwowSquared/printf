#include "holberton.h"

/**
 * printUnsigned - Prints an unsigned int
 * @input: arugments
 * @index: buffer
 * Return: no return
 */
void printUnsigned(va_list input, mods *m, char **index)
{
	unsigned int out = va_arg(input, unsigned int);

	(void)m;

	int_recursion(out, index);
}

/**
 * printOctal - prints a number in octal
 * @input: arugments
 * @index: buffer
 * Return: no return
 */
void printOctal(va_list input, mods *m, char **index)
{
	unsigned int out = va_arg(input, unsigned int);

	if (m->pound)
		_putchar('0', index);

	if (out == 0)
	{
		_putchar(out + 48, index);
		return;
	}
	octal_recursion(out, index);
}

/**
 * octal_recursion - converts and prints a number passed to it in octal
 * @i: number passed
 * @index: buffer
 * Return: no return
 */
void octal_recursion(unsigned int i, char **index)
{
	unsigned int remainder;

	if (i == 0)
		return;

	remainder = i % 8;
	octal_recursion(i / 8, index);
	_putchar(remainder + 48, index);
}

/**
 * printHex - prints a number in hex
 * @input: arugments
 * @index: buffer
 * Return: no return
 */
void printHex(va_list input, mods *m, char **index)
{
	unsigned long int out = va_arg(input, unsigned long int);

	if (m->pound)
	{
		_putchar('0', index);
		_putchar('x', index);
	}

	if (out == 0)
	{
		_putchar(out + 48, index);
		return;
	}
	hex_recursion(out, index);
}

/**
 * hex_recursion - converts and prints a number passed into hex
 * @i: number passed
 * @index: buffer
 * Return: no return
 */
void hex_recursion(unsigned long int i, char **index)
{
	unsigned long int remainder;

	if (i == 0)
		return;
	remainder = i % 16;
	hex_recursion(i / 16, index);
	if (remainder > 9)
		remainder += 39;
	_putchar(remainder + 48, index);
}
