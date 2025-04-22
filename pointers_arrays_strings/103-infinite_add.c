#include "main.h"

/**
 * infinite_add - Adds two numbers stored as strings
 * @n1: First number as string
 * @n2: Second number as string
 * @r: Buffer to store the result
 * @size_r: Size of buffer r
 *
 * Return: Pointer to result, or 0 if result can't fit
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k, len1 = 0, len2 = 0, carry = 0, sum;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	if (len1 >= size_r || len2 >= size_r)
		return (0);

	i = len1 - 1;
	j = len2 - 1;
	k = size_r - 1;
	r[k] = '\0';
	k--;

	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';

		if (k < 0)
			return (0);

		r[k--] = (sum % 10) + '0';
		carry = sum / 10;
	}

	return (r + k + 1);
}

