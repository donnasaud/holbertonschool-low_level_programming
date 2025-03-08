#include "main.h"

/**
 * print_number - Prints numbers with proper spacing.
 * @num: The number to print.
 */
void print_number(int num)
{
	if (num < 10)
	{
		_putchar(' ');
		_putchar(' ');
		_putchar(num + '0');
	}
	else if (num < 100)
	{
		_putchar(' ');
		_putchar((num / 10) + '0');
		_putchar((num % 10) + '0');
	}
	else
	{
		_putchar((num / 100) + '0');
		_putchar(((num / 10) % 10) + '0');
		_putchar((num % 10) + '0');
	}
}

/**
 * print_times_table - Prints the `n` times table, starting with 0.
 * @n: The number to generate the times table for.
 */
void print_times_table(int n)
{
	int row, col, product;

	if (n > 15 || n < 0)
		return;

	for (row = 0; row <= n; row++)
	{
		for (col = 0; col <= n; col++)
		{
			product = row * col;
			if (col == 0)
				_putchar(product + '0');
			else
			{
				_putchar(',');
				_putchar(' ');
				print_number(product);
			}
		}
		_putchar('\n');
	}
}

