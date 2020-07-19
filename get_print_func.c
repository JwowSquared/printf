#include "holberton.h"

void (*get_print_func(char c))(va_list, char **)
{
	spec specs[] = {
		{"c", &printChar},
		{"s", &printString},
		{"%", &printPercent},
		{"d", &printInteger},
		{"i", &printInteger},
		{"b", &printBinary},
		{"u", &printUnsigned},
		{"o", &printOctal},
		{"x", &printHex},
		{"X", &printHex_upper},
		{"R", &printRot},
		{"r", &printReverse},
		{NULL, NULL}
	};
	int i = 0;

	while (specs[i].f != NULL)
	{
		if (*(specs[i].key) == c)
			return (specs[i].f);
		i++;
	}

	return (NULL);
}
