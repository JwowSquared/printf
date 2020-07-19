#include "holberton.h"

void printString_custom(va_list input, char **index)
{
	int i = 0;
	char *str;

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
