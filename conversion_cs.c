#include "printf.h"
#include <stdarg.h>

int printChar(va_list input)
{
	_putchar(va_arg(input, int));
	return (1);
}

int printString(va_list input)
{
	int count = 0;
	char *str;

	str = va_arg(input, const char *);
	if (str == NULL)
		return (0);
	while (str[count])
	{
		_putchar(str[count]);
		count++;
	}
	return (count);
}
