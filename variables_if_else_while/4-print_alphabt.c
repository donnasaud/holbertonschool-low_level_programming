#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase except 'q' and 'e'.
 *
 * Description: Uses a loop to iterate through letters a-z,
 * skipping 'q' and 'e', and prints them using putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter = 'a';

	/* Loop through all lowercase letters */
	while (letter <= 'z')
	{
		/* Skip 'q' and 'e' */
		if (letter != 'q' && letter != 'e')
			putchar(letter);

		letter++;
	}

	/* Print newline */
	putchar('\n');

	return (0);
}

