#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @index: character buffer
 * Return: 1023 if buffer is emptied, else 0
 */
int _putchar(char c, char **index)
{
	int i;

	if (**index)
	{
		**index = c;
		(*index)++;
		return (0);
	}
	(*index) -= 1023;
	write(1, (*index), 1023);
	for (i = 0; i < 1023; i++)
		(*index)[i] = '!';

	**index = c;
	(*index)++;
	return (1023);
}
