#include "holberton.h"

/**
 * printChar - prints a character
 * @input: arugments
 * @index: buffer
 * Return: no return
 */
void printChar(va_list input, char **index)
{
	_putchar(va_arg(input, int), index);
}

/**
 * printString - prints a string
 * @input: arugments
 * @index: buffer
 * Return: no return
 */
void printString(va_list input, char **index)
{
	int count = 0;
	char *str;

	str = va_arg(input, char *);
	if (str == NULL)
		return;
	while (str[count])
	{
		_putchar(str[count], index);
		count++;
	}
}

/**
 * printPercent - Prints a percent sign
 * @input: arugments
 * @index: buffer
 * Return: no return
 */
void printPercent(va_list input, char **index)
{
	(void)input;
	_putchar('%', index);
}
