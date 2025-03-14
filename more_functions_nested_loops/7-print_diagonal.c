#include "main.h"

/**
 * print_diagonal - Draws a diagonal line using `\`
 * @n: The number of times `\` should be printed
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int i, j;

	if (n > 0)
	{
		for (i = 0; i < n; i++) /* Loop for each line */
		{
			for (j = 0; j < i; j++) /* Print spaces before `\` */
				_putchar(' ');

			_putchar('\\'); /* Print the `\` character */
			_putchar('\n'); /* Move to the next line */
		}
	}
	else
	{
		_putchar('\n'); /* Print only a newline if n <= 0 */
	}
}

