#include "holberton.h"
#include <stdio.h>

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

	if (k == 'S' || k == 'r' || k == 'R' || k == 'p' || k == 'b' || k == '%')
		return (f(inp, m, ind));
	for (i = 0; i < 1023; i++)
		buffer[i] = '!';
	buffer[1023] = '\0';
	f(inp, m, b);
	while (&buffer[length] != p)
		length++;
	if (length < m->precision && k != 's')
		j = m->precision - length;
	if (length < m->width)
	{
		i = m->width - length - j;
		if (m->zero)
		{
			flag = '0';
			if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == ' ')
			{
				total += swap_sign(buffer, ind);
				i--;
			}
		}
		while (i-- > 0)
			if (m->minus)
				total += _putchar(' ', b);
			else
				total += _putchar(flag, ind);
	}
	if (j > 0)
		if (buffer[0] == '+' || buffer[0] == '-')
			total += swap_sign(buffer, ind);
	while (j-- > 0)
		total += _putchar('0', ind);
	while (++j < length)
		total += _putchar(buffer[j], ind);
	return (total);
}

/**
* swap_sign - places sign in front of leading zeroes
* @buffer: local buffer
* @ind: output buffer
*
* Return: _putchar return value
*/
int swap_sign(char *buffer, char **ind)
{
	char c = buffer[0];

	buffer[0] = '0';
	return (_putchar(c, ind));
}
