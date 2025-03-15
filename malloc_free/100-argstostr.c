#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of the program
 * @ac: Argument count
 * @av: Argument vector (array of strings)
 *
 * Return: Pointer to new string with all args + '\n', or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	int i, j, k = 0, len = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate total length needed */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++; /* for newline */
	}

	str = malloc(sizeof(char) * (len + 1)); /* +1 for null terminator */
	if (str == NULL)
		return (NULL);

	/* Copy arguments into new string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[k] = av[i][j];
			k++;
		}
		str[k] = '\n';
		k++;
	}

	str[k] = '\0';
	return (str);
}

