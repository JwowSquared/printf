#include "holberton.h"
#include <stdio.h>

/**
 * handle_mods - applies modifiers to our output
 * @f: function to perform with specific argument
 * @m: modifiers
 * @input: arguments
 * @index: buffer
 * Return: no return
 */
void handle_mods(void (*f)(va_list, mods *, char **), mods *m, va_list input, char **index)
{
	char buffer[1024];
	char *p = buffer;
	char **b = &p;
	int i, j = 0, length = 0;
	char flag = ' ';

	for (i = 0; i < 1023; i++)
		buffer[i] = '!';

	f(input, m, b);

	*p = '\0';
	while (buffer[length])
		length++;
	*p = '!';

	if (length < m->precision)
		j = m->precision - length;

	if (length < m->width)
	{
		i = m->width - length - j;

		if (m->zero)
		{
			flag = '0';
			if (buffer[0] == '+' || buffer[0] == '-')
			{
				_putchar(buffer[0], index);
				buffer[0] = '0';
				i--;
			}
		}
		while (i > 0)
		{
			if (m->minus)
				_putchar(' ', b);
			else
				_putchar(flag, index);
			i--;
		}
	}
	while (j > 0)
	{
		_putchar('0', index);
		j--;
	}

	*p = '\0';
	i = 0;
	while (buffer[i])
		_putchar(buffer[i++], index);
}
