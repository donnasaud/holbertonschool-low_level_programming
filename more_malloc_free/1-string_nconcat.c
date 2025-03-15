#include "main.h"

/**
 * string_nconcat - Concatenates two strings up to n bytes of s2
 * @s1: The first string
 * @s2: The second string
 * @n: The maximum number of bytes from s2 to concatenate
 *
 * Return: Pointer to the newly allocated space in memory containing s1
 * followed by the first n bytes of s2, and null terminated.
 * Returns NULL if malloc fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *new_str;

	/* Treat NULL strings as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate the length of s1 and s2 */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* Use full s2 if n is greater or equal to its length */
	if (n >= len2)
		n = len2;

	/* Allocate memory for the new concatenated string */
	new_str = malloc(sizeof(char) * (len1 + n + 1));
	if (new_str == NULL)
		return (NULL);

	/* Copy s1 into new_str */
	for (i = 0; i < len1; i++)
		new_str[i] = s1[i];

	/* Copy first n bytes of s2 into new_str */
	for (j = 0; j < n; j++, i++)
		new_str[i] = s2[j];

	/* Add null terminator */
	new_str[i] = '\0';

	return (new_str);
}

