#include "main.h"

/**
 * check_palindrome - helper function to check palindrome
 * @s: string to check
 * @start: starting index
 * @end: ending index
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (check_palindrome(s, start + 1, end - 1));
}

/**
 * _strlen_recursion - returns length of a string
 * @s: input string
 *
 * Return: length of s
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen_recursion(s + 1));
}

/**
 * is_palindrome - returns 1 if a string is a palindrome, 0 if not
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	if (!s || *s == '\0')
		return (1);

	return (check_palindrome(s, 0, _strlen_recursion(s) - 1));
}

