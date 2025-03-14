#include "main.h"

/**
 * more_numbers - Prints 10 times the numbers from 0 to 14
 *
 * Return: Nothing
 */
void more_numbers(void)
{
	int i, num;

	for (i = 0; i < 10; i++) /* Loop 10 times */
	{
		for (num = 0; num <= 14; num++) /* Print numbers 0 to 14 */
		{
			if (num > 9) /* Print first digit if number is >= 10 */
				_putchar((num / 10) + '0'); /* Extracts tens place */

			_putchar((num % 10) + '0'); /* Extracts ones place */
		}
		_putchar('\n'); /* New line after printing each row */
	}
}

