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
	void (*f)(va_list, mods *, char **);
	va_list input;
	char buffer[1024];
	char *p = buffer;
	char **index = &p;
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
				h_m(f, m, input, index);
				i++;
				continue;
			}
		}
		_putchar(format[i++], index);
	}
	va_end(input);
	free(m);
	**index = '\0';
	while (buffer[total])
		total++;
	write(1, &buffer, total);

	return (total);
}
