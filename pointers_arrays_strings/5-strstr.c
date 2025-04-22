#include "main.h"
#include <stddef.h>  /* For NULL */

/**
 * _strstr - Locates a substring
 * @haystack: The main string to search in
 * @needle: The substring to find
 *
 * Return: Pointer to beginning of located substring, or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i;

	if (*needle == '\0')
		return (haystack);

	while (*haystack != '\0')
	{
		i = 0;
		while (needle[i] != '\0' && haystack[i] == needle[i])
			i++;

		if (needle[i] == '\0')
			return (haystack);

		haystack++;
	}

	return (NULL);
}

