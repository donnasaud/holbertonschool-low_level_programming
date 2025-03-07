#include <stdio.h>

/**
 * main - Prints single-digit numbers of base 10 starting from 0.
 *
 * Description: Uses an integer loop to print numbers 0-9,
 * avoiding char variables.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	/* Loop through digits 0-9 */
	for (num = 0; num < 10; num++)
		putchar(num + '0'); /* Convert int to ASCII and print */

	/* Print newline */
	putchar('\n');

	return (0);
}

