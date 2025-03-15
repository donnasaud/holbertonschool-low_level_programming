#include <stdlib.h>
#include "main.h"

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           containing a duplicate of the string given as a parameter.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if
 *         str is NULL or memory allocation fails.
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* Calculate the length of the string */
	while (str[len] != '\0')
		len++;

	/* Allocate memory for the duplicate string (+1 for null terminator) */
	dup = malloc((len + 1) * sizeof(char));

	if (dup == NULL) /* Check if malloc failed */
		return (NULL);

	/* Copy the string into the newly allocated memory */
	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}

