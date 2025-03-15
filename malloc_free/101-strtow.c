#include "main.h"
#include <stdlib.h>

/**
 * word_count - Counts the number of words in a string
 * @str: The input string
 * Return: Number of words
 */
int word_count(char *str)
{
	int count = 0, i = 0;

	while (str[i])
	{
		if (str[i] != ' ' &&
		   (i == 0 || str[i - 1] == ' '))
			count++;
		i++;
	}
	return (count);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 * Return: Pointer to array of strings, or NULL
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j, k, word_len, wc, start;

	if (str == NULL || *str == '\0')
		return (NULL);

	wc = word_count(str);
	if (wc == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (wc + 1));
	if (words == NULL)
		return (NULL);

	for (j = 0, k = 0; k < wc; k++)
	{
		while (str[j] == ' ')
			j++;
		start = j;
		while (str[j] != ' ' && str[j] != '\0')
			j++;
		word_len = j - start;
		words[k] = malloc(sizeof(char) * (word_len + 1));
		if (words[k] == NULL)
		{
			while (k--)
				free(words[k]);
			free(words);
			return (NULL);
		}
		for (i = 0; i < word_len; i++)
			words[k][i] = str[start + i];
		words[k][i] = '\0';
	}
	words[k] = NULL;
	return (words);
}

