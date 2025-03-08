#include <stdio.h>

/**
 * main - Finds and prints the sum of even Fibonacci numbers below 4,000,000.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int a = 1, b = 2, next;
	long int sum = 2; /* Start with 2 since it's even */

	/* Generate Fibonacci numbers below 4,000,000 */
	while (1)
	{
		next = a + b;
		if (next > 4000000)
			break;

		/* Add to sum if the number is even */
		if (next % 2 == 0)
			sum += next;

		/* Update previous numbers */
		a = b;
		b = next;
	}

	/* Print the sum */
	printf("%ld\n", sum);

	return (0);
}

