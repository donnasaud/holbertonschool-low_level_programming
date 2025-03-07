#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase and uppercase.
 *
 * Description: This program prints all lowercase letters first,
 * then prints all uppercase letters, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char lower = 'a';
	char upper = 'A';

	/* Print lowercase letters */
	while (lower <= 'z')
	{
		putchar(lower);
		lower++;
	}

	/* Print uppercase letters */
	while (upper <= 'Z')
	{
		putchar(upper);
		upper++;
	}

	/* Print newline */
	putchar('\n');

	return (0);
}

