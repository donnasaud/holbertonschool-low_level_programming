#include "main.h"

/**
 * find_sqrt - helper function to find natural square root using recursion
 * @n: number to find the square root of
 * @i: current iterator to test as a possible square root
 *
 * Return: natural square root, or -1 if none exists
 */
int find_sqrt(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find the square root of
 *
 * Return: the natural square root, or -1 if none exists
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (find_sqrt(n, 0));
}

