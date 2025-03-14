#include <stdio.h>

/**
 * main - Finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long number = 612852475143;
	long factor = 2;
	long largest = 0;

	/* Divide number by 2 until it is odd */
	while (number % factor == 0)
	{
		largest = factor;
		number /= factor;
	}

	/* Check odd numbers for prime factors */
	for (factor = 3; factor * factor <= number; factor += 2)
	{
		while (number % factor == 0)
		{
			largest = factor;
			number /= factor;
		}
	}

	/* If number is greater than 1, it is the largest prime factor */
	if (number > 1)
		largest = number;

	printf("%ld\n", largest);
	return (0);
}

