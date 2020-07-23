#include "holberton.h"

/**
 * printString_custom - Prints a string showing special characters as hex
 * @input: arugments
 * @m: modifiers
 * @index: buffer
 * Return: no return
 */
int printString_custom(va_list input, mods *m, char **index)
{
	int i = 0, total = 0;
	char *str;

	(void)m;

	str = va_arg(input, char *);
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			total += _putchar('\\', index);
			total += _putchar('x', index);
			if (str[i] < 16)
				total += _putchar('0', index);
			total += hex_recursion_upper(str[i++], index);
		}
		else
			total += _putchar(str[i++], index);
	}

	return (total);
}
