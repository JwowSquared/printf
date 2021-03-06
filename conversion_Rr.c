#include "holberton.h"

/**
 * printRot - Prints rot conversion of number
 * @input: arugment to handle
 * @index: buffer
 * @m: modifiers not used
 * Return: no return
 */
int printRot(va_list input, mods *m, char **index)
{
	int count = 0, i = 0, k = 0, total = 0;
	char *str, *s, s1[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char s2[] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";

	(void)m;
	s = va_arg(input, char *);
	if (s == NULL)
		return (0);

	while (s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);

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
		total += _putchar(str[count], index);
		count++;
	}
	free(str);
	return (total);
}

/**
 * printReverse - prints a string in reverse
 * @input: arugment to handle
 * @index: buffer
 * @m: modifiers not used
 * Return: no return
 */
int printReverse(va_list input, mods *m, char **index)
{
	int count = 0, i = 0, length = 0, total = 0;
	char *s, *e, *str, *in;
	char temp;

	(void)m;
	in = va_arg(input, char *);
	if (in == NULL)
		return (0);

	while (in[length])
		length++;
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (0);

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
		total += _putchar(str[count], index);
	free(str);
	return (total);
}
