#include "holberton.h"
#include <stdio.h>
int swap_signs(char *buffer, char **ind, int *i);
/**
 * h_m - applies modifiers to our output
 * @f: function to perform with specific argument
 * @m: modifiers
 * @inp: arguments
 * @ind: buffer
 * Return: no return
 */
int h_m(int (*f)(va_list, mods *, char **), mods *m, va_list inp, char **ind)
{
	char buffer[1024], *p = buffer, **b = &p, flag = ' ', k = m->key;
	int i, j = 0, length = 0, total = 0;

	if (m->basic)
		return (f(inp, m, ind));
	buffer_init(b);
	total += f(inp, m, b);
	while (&buffer[length] != p)
		length++;
	if (length <= m->precision && k != 's')
	{
		j = m->precision - length;
		if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == ' ')
			j++;
	}
	if (length < m->width)
	{
		i = m->width - length - j;
		if (m->zero)
		{
			flag = '0';
			if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == ' ')
				total += swap_signs(buffer, ind, &i);
		}
		while (i-- > 0)
			if (m->minus)
			{
				total += _putchar(' ', b);
				length++;
			}
			else
				total += _putchar(flag, ind);
	}
	if (j > 0)
		if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == ' ')
			total += swap_signs(buffer, ind, &j);
	while (j-- > 0)
		total += _putchar('0', ind);
	while (++j < length)
		total += _putchar(buffer[j], ind);
	return (total);
}

/**
* swap_signs - places sign in front of leading zeroes
* @buffer: local buffer
* @ind: output buffer
* @i: pointer to iterator to decrement in h_m
*
* Return: _putchar return value
*/
int swap_signs(char *buffer, char **ind, int *i)
{
	char c = buffer[0];

	buffer[0] = '0';
	(*i)--;
	return (_putchar(c, ind));
}
