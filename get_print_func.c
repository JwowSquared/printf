#include "holberton.h"

/**
 * get_print_func - associates function with matching specifier
 * @c: format specifier
 *
 * Return: the function that matches specifier
 */
void (*get_print_func(char c))(va_list, mods *, char **)
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
		{"S", &printString_custom},
		{"p", &printAddress},
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
