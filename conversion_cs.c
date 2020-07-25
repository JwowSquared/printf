#include "holberton.h"

/**
 * printChar - prints a character
 * @input: arugment to handle
 * @index: buffer
 * @m: modifiers
 * Return: no return
 */
int printChar(va_list input, mods *m, char **index)
{
	(void)m;
	return (_putchar(va_arg(input, int), index));
}

/**
 * printString - prints a string
 * @input: arugment to handle
 * @index: buffer
 * @m: modifiers
 * Return: no return
 */
int printString(va_list input, mods *m, char **index)
{
	int count = 0, total = 0;
	char *str;

	if (m->precision == -1)
		m->precision = 1024;

	str = va_arg(input, char *);
	if (str == NULL)
		str = "(null)";
	while (str[count] && count < m->precision)
	{
		total += _putchar(str[count], index);
		count++;
	}
	m->precision = -1;
	return (total);
}

/**
 * printPercent - Prints a percent sign
 * @input: arugment to handle
 * @index: buffer
 * @m: modifiers
 * Return: no return
 */
int printPercent(va_list input, mods *m, char **index)
{
	(void)input;
	(void)m;
	return (_putchar('%', index));
}
