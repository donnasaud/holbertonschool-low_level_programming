#include "main.h"

/**
 * _isalpha - Checks if a character is a letter (A-Z or a-z).
 * @c: The character to check.
 *
 * Return: 1 if c is a letter, 0 otherwise.
 */
int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

