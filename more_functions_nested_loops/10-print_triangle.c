#include "main.h"

/**
 * print_triangle - Prints a right-aligned triangle using `#`
 * @size: The size of the triangle
 *
 * Description: Prints a triangle of `#` characters where
 * the base and height are equal to `size`.
 * If `size` is 0 or less, prints only a newline.
 */
void print_triangle(int size)
{
	int row, space, hash;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 1; row <= size; row++)
	{
		/* Print leading spaces */
		for (space = size - row; space > 0; space--)
		{
			_putchar(' ');
		}

		/* Print `#` characters */
		for (hash = 1; hash <= row; hash++)
		{
			_putchar('#');
		}

		_putchar('\n'); /* New line after each row */
	}
}

