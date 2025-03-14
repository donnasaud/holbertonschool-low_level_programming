#include "main.h"

/**
 * _isdigit - Checks if a character is a digit (0-9)
 * @c: The character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
    if (c >= '0' && c <= '9') /* Check if c is between ASCII 48 ('0') and 57 ('9') */
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

