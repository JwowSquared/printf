#include "holberton.h"
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - Takes arguments and prints them to console
 * @format: String to print with specifiers and mods
 * Return: character length
 */
int _printf(const char *format, ...)
{
	int i = 0, k = 0, c = 0, total = 0, *j = &i;
	int (*f)(va_list, mods *, char **);
	va_list input;
	char buffer[1024], *p = buffer, **index = &p;
	mods *m = malloc(sizeof(mods));

	if (m == NULL || format == NULL)
		return (-1);
	for (k = 0; k < 1023; k++)
		buffer[k] = '!';
	buffer[1023] = '\0';
	va_start(input, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			get_mods(format, m, j);
			if (m->key != '\0')
			{
				f = get_print_func(m->key);
				total += h_m(f, m, input, index);
				i++;
				continue;
			}
			i++;
			if (m->eos)
				break;
		}
		total += _putchar(format[i++], index);
	}
	va_end(input);
	free(m);
	**index = '\0';
	while (buffer[c] || buffer + c != *index)
		c++;
	write(1, &buffer, c);
	return (total + c);
}
