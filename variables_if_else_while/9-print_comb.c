#include <stdio.h>

/**
 * main - Prints all possible combinations of single-digit numbers.
 *
 * Description: Numbers are printed in ascending order,
 * separated by ', ' using only putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	/* Loop through numbers 0 to 9 */
	for (num = 0; num <= 9; num++)
	{
		putchar(num + '0'); /* Convert integer to character */

		/* Print ", " if it's not the last digit */
		if (num != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	/* Print newline */
	putchar('\n');

	return (0);
}

