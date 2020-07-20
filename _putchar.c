#include <stdio.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @index: character buffer
 * Return: no return
 */
void _putchar(char c, char **index)
{
	if (**index)
	{
		**index = c;
		(*index)++;
	}
}
