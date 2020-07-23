#include "holberton.h"
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - Takes arguments and prints them to console
 * @format: String to print with specifiers
 * Return: character length
 */
int _printf(const char *format, ...)
{
	int i = 0, total = 0, *j = &i;
	int (*f)(va_list, mods *, char **);
	va_list input;
	char buffer[1024], *p = buffer, **index = &p;
	mods *m = malloc(sizeof(mods));

	if (m == NULL)
		return (-1);

	for (i = 0; i < 1023; i++)
		buffer[i] = '!';
	buffer[1023] = '\0';
	va_start(input, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			get_mods(format, m, j);
			f = get_print_func(m->key);
			if (f != NULL)
			{
				total += h_m(f, m, input, index);
				i++;
				continue;
			}
			else
				i--;
		}
		total += _putchar(format[i++], index);
	}
	va_end(input);
	free(m);
	i = 0;
	**index = '\0';
	while (buffer[i])
		i++;
	write(1, &buffer, i);
	return (total + i);
}
