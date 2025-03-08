#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers starting from 1 and 2.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count;
	long int a = 1, b = 2, next;

	/* Print the first Fibonacci number */
	printf("%ld, %ld", a, b);

	/* Loop to print remaining Fibonacci numbers */
	for (count = 2; count < 50; count++)
	{
		next = a + b;
		printf(", %ld", next);

		/* Update previous numbers */
		a = b;
		b = next;
	}

	/* Print a newline at the end */
	printf("\n");

	return (0);
}

