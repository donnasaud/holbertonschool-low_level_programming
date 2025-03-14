#include "main.h"

/**
 * print_line - Draws a straight line using `_`
 * @n: The number of times `_` should be printed
 *
 * Return: void
 */
void print_line(int n)
{
	int i;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
			_putchar('_'); /* Print _ n times */
	}
	_putchar('\n'); /* Print a newline at the end */
}

