#include "holberton.h"
#include <stdio.h>

mods *get_mods(char *format, int *i)
{
	mods *out = mods_init();
	char *keys = "cs%dibuoxXSprR";
	int match = 1, j, k = (*i);
	int *p = &k;

	while (match)
	{
		switch (format[k])
		{
			case ' ':
				out->zero = 0;
				k++;
				break;
			case '0':
				out->zero = 1;
				k++;
				break;
			case '+':
				out->plus = 1;
				k++;
				break;
			case '-':
				out->minus = 1;
				k++;
				break;
			case '#':
				out->pound = 1;
				k++;
				break;
			default:
				match = 0;
		}
	}

	out->width = get_int(format, p);
	if (out->width == -1)
		return (NULL);

	if (format[k] == '.')
	{
		k++;
		out->precision = get_int(format, p);
		if (out->precision == -1)
			return (NULL);
	}

	if (format[k] == 'l' || format[k] == 'h')
		out->length = format[k++];

	match = 0;
	for (j = 0; keys[j]; j++)
	{
		if (keys[j] == format[k])
		{
			out->key = format[k];
			match = 1;
			break;
		}
	}

	if (match != 1)
	{
		/* abort mission */
		return (NULL);
	}
	else
	{
		(*i) = k;
		return (out);
	}
}

mods *mods_init(void)
{
	mods *out = malloc(sizeof(mods));
	if (out == NULL)
		return (NULL);

	out->zero = 0;
	out->plus = 0;
	out->pound = 0;
	out->minus = 0;
	out->width = 0;
	out->precision = 0;
	out->length = '\0';
	out->key = '\0';

	return (out);
}

int get_int(char *format, int *i)
{
	char buffer[5];
	int b = 0;
	
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		if (b > 3)
			return (-1);
		buffer[b] = format[*i];
		b++;
		(*i)++;
	}
	buffer[b] = '\0';
	return (_atoi(buffer));
}

int _atoi(char *buffer)
{
	int i, total = 0;

	for (i = 0; buffer[i]; i++)
	{
		total *= 10;
		total += (buffer[i] - 48);
	}

	return (total);
}
