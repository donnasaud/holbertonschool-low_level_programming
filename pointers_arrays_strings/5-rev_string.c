#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: the string to be reversed
 */
void rev_string(char *s)
{
	int i = 0, j;
	char temp;

	/* Find the length of the string */
	while (s[i] != '\0')
		i--;

	i--; /* Move to the last valid character (not '\0') */

	/* Swap characters from start to end */
	for (j = 0; j < i; j++, i--)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
	}
}

