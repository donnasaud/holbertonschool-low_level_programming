#include "main.h"

/**
 * print_square - Prints a square using the `#` character
 * @size: The size of the square
 *
 * Return: void
 */
void print_square(int size)
{
	int row, col;

	if (size > 0)
	{
		for (row = 0; row < size; row++) /* Loop for rows */
		{
			for (col = 0; col < size; col++) /* Loop for columns */
				_putchar('#'); /* Print `#` */

			_putchar('\n'); /* Move to the next row */
		}
	}
	else
	{
		_putchar('\n'); /* Print only a newline if size <= 0 */
	}
}

