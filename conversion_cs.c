#include "holberton.h"

/**
 * printChar - prints a character
 * @input: arugments
 * @index: buffer
 * @m: modifiers
 * Return: no return
 */
void printChar(va_list input, mods *m, char **index)
{
	(void)m;
	_putchar(va_arg(input, int), index);
}

/**
 * printString - prints a string
 * @input: arugments
 * @index: buffer
 * @m: modifiers
 * Return: no return
 */
void printString(va_list input, mods *m, char **index)
{
	int count = 0;
	char *str;

	if (m->precision == -1)
		m->precision = 1024;

	str = va_arg(input, char *);
	if (str == NULL)
		str = "(null)";
	while (str[count] && count < m->precision)
	{
		_putchar(str[count], index);
		count++;
	}
	m->precision = -1;
}

/**
 * printPercent - Prints a percent sign
 * @input: arugments
 * @index: buffer
 * @m: modifiers
 * Return: no return
 */
void printPercent(va_list input, mods *m, char **index)
{
	(void)input;
	(void)m;
	_putchar('%', index);
}
