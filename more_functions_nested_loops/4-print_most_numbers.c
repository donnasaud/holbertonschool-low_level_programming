#include "main.h"

/**
 * print_most_numbers - Prints numbers from 0 to 9 (except 2 and 4)
 *
 * Return: Nothing
 */
void print_most_numbers(void)
{
	int num;

	for (num = 0; num <= 9; num++)
	{
		if (num != 2 && num != 4) /* Skip 2 and 4 */
			_putchar(num + '0'); /* Convert int to char */
	}
	_putchar('\n'); /* Print newline */
}

