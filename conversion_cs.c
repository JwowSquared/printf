#include "holberton.h"

void printChar(va_list input, char **index)
{
	_putchar(va_arg(input, int), index);
}

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

void printPercent(va_list input, char **index)
{
	(void)input;
	_putchar('%', index);
}
