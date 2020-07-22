#include "holberton.h"
#include <stdio.h>

/**
 * h_m - applies modifiers to our output
 * @f: function to perform with specific argument
 * @m: modifiers
 * @inp: argument to handle
 * @ind: buffer
 * Return: no return
 */
void h_m(void (*f)(va_list, mods *, char **), mods *m, va_list inp, char **ind)
{
	char buffer[1024], *p = buffer, **b = &p, flag = ' ';
	int i, j = 0, length = 0;

	for (i = 0; i < 1023; i++)
		buffer[i] = '!';
	f(inp, m, b);
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
				_putchar(buffer[0], ind);
				buffer[0] = '0';
				i--;
			}
		}
		while (i > 0)
			if (m->minus)
				_putchar(' ', b);
			else
				_putchar(flag, ind);
			i--;
	}
	while (j-- > 0)
		_putchar('0', ind);

	*p = '\0';
	i = 0;
	while (buffer[i])
		_putchar(buffer[i++], ind);
}
