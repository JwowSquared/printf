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
	int i = 0, c = 0, total = 0, *j = &i;
	int (*f)(va_list, mods *, char **);
	va_list input;
	char buffer[1024], *p = buffer, **index = &p;
	mods *m = malloc(sizeof(mods));

	if (m == NULL || format == NULL)
		return (-1);
	buffer_init(index);
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
			if (m->eos)
			{
				free(m);
				return (-1);
			}
			total += _putchar('%', index);
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

/**
* buffer_init - initializes the buffer to non NULL memory
* @buffer: buffer to initialize
*/
void buffer_init(char **buffer)
{
	int i = 0;

	for (i = 0; i < 1023; i++)
		(*buffer)[i] = '!';
	(*buffer)[1023] = '\0';
}
