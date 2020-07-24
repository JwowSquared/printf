#include "holberton.h"
#include <stdio.h>

/**
 * get_mods - finds all of the modifiers of argument call
 * @format: temp string buffer
 * @out: output modifiers
 * @i: buffer index
 * @input: va_list to pass to get_int
 * Return: no return
 */
void get_mods(const char *format, mods *out, int *i, va_list input)
{
	char *keys = "cs%dibuoxXSprR";
	int j, k = (*i);
	int *p = &k;

	mods_init(out);

	k = handle_flags(format, out, k);
	out->width = get_int(format, p, input);
	if (out->width == -1)
	{
		mods_init(out);
		return;
	}

	if (format[k] == '.')
	{
		k++;
		out->precision = get_int(format, p, input);
		if (out->precision == -1)
		{
			mods_init(out);
			return;
		}
	}

	if (format[k] == 'l' || format[k] == 'h')
		out->length = format[k++];

	for (j = 0; keys[j]; j++)
		if (keys[j] == format[k])
		{
			out->key = format[k];
			break;
		}

	(*i) = k;
	if (format[k] == '\0')
		out->eos = 1;
}

/**
 * mods_init - initializes and resets a mod type
 * @out: modifiers
 * Return: no return
 */
void mods_init(mods *out)
{
	out->eos = 0;
	out->space = 0;
	out->zero = 0;
	out->plus = 0;
	out->pound = 0;
	out->minus = 0;
	out->width = 0;
	out->precision = -1;
	out->length = '\0';
	out->key = '\0';
}

/**
 * get_int - creates number from string in buffer
 * @format: buffer
 * @i: buffer index
 * @input: va_list to pull width from in case of *
 * Return: new number
 */
int get_int(const char *format, int *i, va_list input)
{
	char buffer[5];
	int b = 0;

	if (format[*i] == '*')
	{
		(*i)++;
		return (va_arg(input, int));
	}

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

/**
 * _atoi - creates integer from string
 * @buffer: character buffer
 * Return: new number
 */
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

/**
* handle_flags - parses format to determine what flags to set
* @format: input string
* @out: mods pointer
* @k: current index on format to look at
*
* Return: k to continue iterating
*/
int handle_flags(const char *format, mods *out, int k)
{
	int match = 1;

	while (match)
	{
		switch (format[k])
		{
			case ' ':
				out->space = 1;
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

	return (k);
}
