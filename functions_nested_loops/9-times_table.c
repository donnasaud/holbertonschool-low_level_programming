#include "main.h"

/**
 * times_table - Prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int i, j, product;

	for (i = 0; i <= 9; i++) /* Loop through rows */
	{
		for (j = 0; j <= 9; j++) /* Loop through columns */
		{
			product = i * j; /* Calculate product */

			if (j > 0) /* Print comma and space after the first number */
			{
				_putchar(',');
				_putchar(' ');
				if (product < 10) /* If single digit, print extra space */
					_putchar(' ');
			}

			/* Print the product */
			if (product < 10)
				_putchar(product + '0'); /* Convert to character */
			else
			{
				_putchar((product / 10) + '0'); /* Print tens place */
				_putchar((product % 10) + '0'); /* Print ones place */
			}
		}
		_putchar('\n'); /* New line after each row */
	}
}

