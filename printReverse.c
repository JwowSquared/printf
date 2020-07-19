#include "holberton.h"

void printReverse(va_list input, char **index)
{
	int count = 0, i;
	char *s;
	char *e;
	char temp;
	char *str;

	str = va_arg(input, char *);
	if (str == NULL)
		return;
	s = str;
	e = str;
	while (str[count])
		count++;
	for (i = 0; i < count - 1; i++)
		e++;
	while (e > s)
	{
		temp = *e;
		*e = *s;
		*s = temp;
		e--;
		s++;
	}
	count = 0;
	while (str[count])
	{
		_putchar(str[count], index);
		count++;
	}
}
