#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Assigns a random number to n and prints whether it is
 * positive, negative, or zero.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	/* Generate random number */
	srand(time(0));
	n = rand() - RAND_MAX / 2;

	/* Check and print whether the number is positive, zero, or negative */
	if (n > 0)
	{
		printf("%d is positive\n", n);
	}
	else if (n == 0)
	{
		printf("%d is zero\n", n);
	}
	else
	{
		printf("%d is negative\n", n);
	}

	return (0);
}


