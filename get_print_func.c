#include "holberton.h"

int (*get_print_func(char *s))(va_list)
{
	spec specs[] = {
		{"c", &printChar},
		{"s", &printString},
		{"d", &printInteger},
		{"i", &printInteger},
		{"b", &printBinary},
		{NULL, NULL}
	};
	int i = 0;

	while (specs[i].f != NULL)
	{
		if (*(specs[i].key) == *s)
			return (specs[i].f);
		i++;
	}

	return (NULL);
}
