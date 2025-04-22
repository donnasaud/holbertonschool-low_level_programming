#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sums of two diagonals of a square matrix
 * @a: Pointer to the first element of the matrix
 * @size: The size of the square matrix
 *
 * Return: Nothing
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum_main = 0, sum_secondary = 0;

	for (i = 0; i < size; i++)
	{
		sum_main += a[i * size + i];
		sum_secondary += a[i * size + (size - 1 - i)];
	}

	printf("%d, %d\n", sum_main, sum_secondary);
}

