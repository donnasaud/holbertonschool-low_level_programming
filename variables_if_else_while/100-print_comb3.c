#include <stdio.h>

/**
 * main - Prints all possible different combinations of two digits.
 *
 * Description: Numbers are printed in ascending order, separated by ", ".
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;

	/* Loop for the first digit */
	for (i = 0; i <= 8; i++)
	{
		/* Loop for the second digit (always greater than first) */
		for (j = i + 1; j <= 9; j++)
		{
			putchar(i + '0'); /* Convert first digit to char */
			putchar(j + '0'); /* Convert second digit to char */

			/* Print ", " unless it's the last pair (89) */
			if (i != 8 || j != 9)
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

