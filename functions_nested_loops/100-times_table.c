#include "main.h"

/**
 * print_times_table - Prints the `n` times table, starting with 0.
 * @n: The number to generate the times table for.
 *
 * Return: void
 */
void print_times_table(int n)
{
	int row, col, product;

	/* If n is out of range, do nothing */
	if (n > 15 || n < 0)
		return;

	/* Loop through rows (0 to n) */
	for (row = 0; row <= n; row++)
	{
		for (col = 0; col <= n; col++)
		{
			product = row * col;

			/* Print the first number without formatting */
			if (col == 0)
				_putchar(product + '0');
			else
			{
				_putchar(',');
				_putchar(' ');

				/* Proper spacing for numbers */
				if (product < 10)
				{
					_putchar(' ');
					_putchar(' ');
					_putchar(product + '0');
				}
				else if (product < 100)
				{
					_putchar(' ');
					_putchar((product / 10) + '0');
					_putchar((product % 10) + '0');
				}
				else
				{
					_putchar((product / 100) + '0');
					_putchar(((product / 10) % 10) + '0');
					_putchar((product % 10) + '0');
				}
			}
		}
		_putchar('\n'); /* Move to new line after each row */
	}
}

