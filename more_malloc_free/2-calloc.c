#include "main.h"

/**
 * _calloc - Allocates memory for an array and initializes it to zero.
 * @nmemb: Number of elements in the array.
 * @size: Size of each element in bytes.
 *
 * Return: Pointer to the allocated memory or NULL if it fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *memory;

	/* If nmemb or size is 0, return NULL */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Allocate memory for nmemb elements of size bytes each */
	memory = malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);

	/* Initialize allocated memory to zero */
	for (i = 0; i < (nmemb * size); i++)
		memory[i] = 0;

	return (memory);
}

