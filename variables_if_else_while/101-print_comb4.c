#include <stdio.h>

/**
 * main - Prints all possible different combinations of three digits.
 *
 * Description: Numbers are printed in ascending order, separated by ", ".
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j, k;

	/* Loop for first digit */
	for (i = 0; i <= 7; i++)
	{
		/* Loop for second digit (greater than first) */
		for (j = i + 1; j <= 8; j++)
		{
			/* Loop for third digit (greater than second) */
			for (k = j + 1; k <= 9; k++)
			{
				putchar(i + '0'); /* Convert first digit to char */
				putchar(j + '0'); /* Convert second digit to char */
				putchar(k + '0'); /* Convert third digit to char */

				/* Print ", " unless it's the last combination (789) */
				if (i != 7 || j != 8 || k != 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	/* Print newline */
	putchar('\n');

	return (0);
}

