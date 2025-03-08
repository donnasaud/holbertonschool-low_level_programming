#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count;
	unsigned long int a = 1, b = 2, next;
	unsigned long int a_high, a_low, b_high, b_low, next_high, next_low;
	
	printf("%lu, %lu", a, b); /* Print first two numbers */

	for (count = 3; count <= 98; count++)
	{
		if (a + b < a) /* Overflow occurs, switch to two-part handling */
		{
			a_high = a / 1000000000;
			a_low = a % 1000000000;
			b_high = b / 1000000000;
			b_low = b % 1000000000;
			break;
		}
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}

	/* Handling large Fibonacci numbers by splitting into high/low parts */
	while (count <= 98)
	{
		next_low = (a_low + b_low) % 1000000000;
		next_high = a_high + b_high + ((a_low + b_low) / 1000000000);
		
		printf(", %lu%09lu", next_high, next_low);

		a_high = b_high;
		a_low = b_low;
		b_high = next_high;
		b_low = next_low;

		count++;
	}

	printf("\n");
	return (0);
}

