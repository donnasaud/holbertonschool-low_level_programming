#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number.
 * @n: The input number.
 *
 * Return: The last digit.
 */
int print_last_digit(int n)
{
	int last_digit;

	/* Extract the last digit */
	last_digit = n % 10;

	/* Convert negative last digit to positive */
	if (last_digit < 0)
		last_digit *= -1;

	/* Print the last digit */
	_putchar(last_digit + '0');

	return (last_digit);
}

