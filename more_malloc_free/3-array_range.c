#include "main.h"

/**
 * array_range - Creates an array of integers from min to max.
 * @min: The minimum integer value.
 * @max: The maximum integer value.
 *
 * Return: Pointer to the new array, or NULL if allocation fails or min > max.
 */
int *array_range(int min, int max)
{
	int *arr;
	int i, size;

	/* If min is greater than max, return NULL */
	if (min > max)
		return (NULL);

	/* Calculate size of the array */
	size = max - min + 1;

	/* Allocate memory for the array */
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		return (NULL);

	/* Fill the array with values from min to max */
	for (i = 0; i < size; i++)
		arr[i] = min + i;

	return (arr);
}

