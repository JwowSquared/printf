#include "holberton.h"
#include <stdio.h>
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @index: character buffer
 * Return: 1023 if buffer is emptied, else 0
 */
int _putchar(char c, char **index)
{
	if (**index)
	{
		**index = c;
		(*index)++;
		return (0);
	}
	(*index) -= 1023;
	write(1, (*index), 1023);
	buffer_init(index);

	**index = c;
	(*index)++;
	return (1023);
}
