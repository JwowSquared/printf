#include "holberton.h"

void printRot(va_list input, char **index)
{
	int count = 0;
	char *str;

	str = va_arg(input, char *);
	if (str == NULL)
		return;

	char s1[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	char s2[] = "nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM";
	int i, k;

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
}
