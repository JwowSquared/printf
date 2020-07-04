#include "holberton.h"
#include <stdio.h>
int _printf(const char *format, ...)
{
	int i = 0, total = 0;
	int (*f)(va_list);
	va_list input;

	va_start(input, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			f = get_print_func(format[i + 1]);
			if (f != NULL)
			{
				i = i + 2;
				total += f(input);
				continue;
			}
		}
		total += _putchar(format[i++]);
	}

	va_end(input);

	return (total);
}
