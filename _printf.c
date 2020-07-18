#include "holberton.h"
#include <stdio.h>
#include <unistd.h>
int _printf(const char *format, ...)
{
	int i = 0, total = 0;
	void (*f)(va_list, char **);
	va_list input;
	char buffer[1024];
	char *p = buffer;
	char **index = &p;

	for (i = 0; i < 1023; i++)
		buffer[i] = '!';
	buffer[1023] = '\0';

	va_start(input, format);

	i = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			f = get_print_func(format[i + 1]);
			if (f != NULL)
			{
				i = i + 2;
				f(input, index);
				continue;
			}
		}
		_putchar(format[i++], index);
	}

	va_end(input);

	**index = '\0';

	while (buffer[total])
		total++;

	write(1, &buffer, total);

	return (total);
}
