#include <stdio.h>

/**
 * main - Prints all numbers of base 16 in lowercase.
 *
 * Description: Uses putchar to print numbers '0' to '9'
 * and letters 'a' to 'f', followed by a newline.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char digit;

	/* Print numbers '0' to '9' */
	for (digit = '0'; digit <= '9'; digit++)
		putchar(digit);

	/* Print letters 'a' to 'f' */
	for (digit = 'a'; digit <= 'f'; digit++)
		putchar(digit);

	/* Print newline */
	putchar('\n');

	return (0);
}

