#include "holberton.h"

/**
 * printString_custom - Prints a string showing special characters as hex
 * @input: arugments
 * @index: buffer
 * Return: no return
 */
void printString_custom(va_list input, mods *m, char **index)
{
	int i = 0;
	char *str;

	(void)m;

	str = va_arg(input, char *);
	if (str == NULL)
		return;
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\', index);
			_putchar('x', index);
			hex_recursion(str[i++], index);
		}
		else
			_putchar(str[i++], index);
	}
}
