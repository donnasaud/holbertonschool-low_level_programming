#include "main.h"

/**
 * print_numbers - Prints digits 0 to 9
 *
 * Return: Nothing
 */
void print_numbers(void)
{
	int num;

	for (num = 0; num <= 9; num++)
		_putchar(num + '0'); /* Convert integer to character */

	_putchar('\n'); /* Print newline */
}

