#include <stdio.h>

/**
 * main - Prints all possible different combinations of two two-digit numbers.
 *
 * Description: Numbers are printed in ascending order, separated by ", ".
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n1, n2;

	/* Loop for first number (00 to 98) */
	for (n1 = 0; n1 <= 98; n1++)
	{
		/* Loop for second number (n1 + 1 to 99) */
		for (n2 = n1 + 1; n2 <= 99; n2++)
		{
			putchar((n1 / 10) + '0'); /* Print first digit of first number */
			putchar((n1 % 10) + '0'); /* Print second digit of first number */
			putchar(' '); /* Print space */
			putchar((n2 / 10) + '0'); /* Print first digit of second number */
			putchar((n2 % 10) + '0'); /* Print second digit of second number */

			/* Print ", " unless it's the last combination (98 99) */
			if (!(n1 == 98 && n2 == 99))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}

	/* Print newline */
	putchar('\n');

	return (0);
}

