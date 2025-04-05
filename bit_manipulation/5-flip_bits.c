#include "main.h"

/**
 * flip_bits - Counts number of bits to flip to get from one number to another
 * @n: First number
 * @m: Second number
 *
 * Return: Number of bits that need to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int count = 0;

	while (xor)
	{
		count += xor & 1;
		xor >>= 1;
	}

	return (count);
}

