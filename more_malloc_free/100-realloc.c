#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: Pointer to the old memory block.
 * @old_size: Size of the old memory block.
 * @new_size: Size of the new memory block.
 *
 * Return: Pointer to the new memory block, or NULL if failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i;

	/* Case 1: If new_size is the same as old_size, return ptr */
	if (new_size == old_size)
		return (ptr);

	/* Case 2: If ptr is NULL, behave like malloc(new_size) */
	if (ptr == NULL)
		return (malloc(new_size));

	/* Case 3: If new_size is 0 and ptr is not NULL, free ptr and return NULL */
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	/* Case 4: Allocate new memory */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/* Copy the content from old block to new block (up to min(old_size, new_size)) */
	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr[i] = ((char *)ptr)[i];

	/* Free old memory */
	free(ptr);

	return (new_ptr);
}

