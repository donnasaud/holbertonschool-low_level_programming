#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char
 * @s: Double pointer to modify
 * @to: The string to point to
 *
 * Return: Nothing
 */
void set_string(char **s, char *to)
{
	*s = to;
}

