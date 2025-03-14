#include <stdio.h>

/**
 * main - Prints numbers from 1 to 100 with FizzBuzz rules.
 *
 * Description: For multiples of 3, print "Fizz".
 * For multiples of 5, print "Buzz".
 * For multiples of both 3 and 5, print "FizzBuzz".
 * Numbers are space-separated.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	int num;

	for (num = 1; num <= 100; num++)
	{
		if (num % 3 == 0 && num % 5 == 0) /* Multiple of both 3 & 5 */
			printf("FizzBuzz");
		else if (num % 3 == 0) /* Multiple of 3 */
			printf("Fizz");
		else if (num % 5 == 0) /* Multiple of 5 */
			printf("Buzz");
		else
			printf("%d", num); /* Print the number */

		if (num < 100)
			printf(" "); /* Print space between numbers */
	}
	printf("\n"); /* Print new line at the end */

	return (0);
}

