#include "holberton.h"

void printRot(va_list input, char **index)
{
	int count = 0, i = 0, k = 0;
	char *str, *s;
	char s1[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char s2[] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";

	s = va_arg(input, char *);
	if (s == NULL)
		return;

	while (s[i])
		i++;

	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return;

	while (k <= i)
	{
		str[k] = s[k];
		k++;
	}

	for (i = 0; str[i] != '\0'; i++)
		for (k = 0; s1[k] != '\0'; k++)
			if (str[i] == s1[k])
			{
				str[i] = s2[k];
				break;
			}

	while (str[count])
	{
		_putchar(str[count], index);
		count++;
	}

	free(str);
}

void printReverse(va_list input, char **index)
{
	int count = 0, i = 0, length = 0;
	char *s, *e, *str, *in;
	char temp;

	in = va_arg(input, char *);
	if (in == NULL)
		return;

	while (in[length])
		length++;

	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return;

	while (i <= length)
	{
		str[i] = in[i];
		i++;
	}

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

	for (count = 0; str[count]; count++)
		_putchar(str[count], index);

	free(str);
}
