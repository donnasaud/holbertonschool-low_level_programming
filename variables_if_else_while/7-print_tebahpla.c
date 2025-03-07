#include <stdio.h>

/**
 * main - Prints the lowercase alphabet in reverse.
 *
 * Description: Uses a loop to print letters from 'z' to 'a'
 * using only the putchar function.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	/* Loop from 'z' to 'a' */
	for (letter = 'z'; letter >= 'a'; letter--)
		putchar(letter); /* Print letter */

	/* Print newline */
	putchar('\n');

	return (0);
}

