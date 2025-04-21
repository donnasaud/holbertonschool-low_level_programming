#include "main.h"

/**
 * print_rev - prints a string in reverse followed by a newline
 * @s: the string to be reversed and printed
 */
void print_rev(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	while (len--)
		_putchar(s[len]);

	_putchar('\n');
}

