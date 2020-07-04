#include "holberton.h"

int printChar(va_list input)
{
	_putchar(va_arg(input, int));
	return (1);
}

int printString(va_list input)
{
	int count = 0;
	char *str;

	str = va_arg(input, char *);
	if (str == NULL)
		return (0);
	while (str[count])
	{
		_putchar(str[count]);
		count++;
	}
	return (count);
}

int printPercent(va_list input)
{
	(void)input;
	_putchar('%');
	return (1);
}