#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_number - Checks if a string contains only digits.
 * @s: The string to check.
 *
 * Return: 1 if the string is a number, 0 otherwise.
 */
int is_number(char *s)
{
	int i = 0;

	if (!s || s[0] == '\0')
		return (0);

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * multiply - Multiplies two large numbers stored as strings.
 * @num1: First number as a string.
 * @num2: Second number as a string.
 *
 * Return: Pointer to the resulting product as a string.
 */
char *multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, i, j, carry, n1, n2, sum;
    int *result;
    char *final_result;

    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;

    /* Allocate memory for the result */
    result = calloc(len1 + len2, sizeof(int));
    if (!result)
        return (NULL);

    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = num1[i] - '0';
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = n1 * n2 + result[i + j + 1] + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        result[i + j + 1] += carry;
    }

    /* Allocate memory for the final result */
    final_result = malloc(len1 + len2 + 1);
    if (!final_result)
    {
        free(result);
        return (NULL);
    }

    j = 0;
    for (i = 0; i < len1 + len2; i++)
    {
        if (!(j == 0 && result[i] == 0))
            final_result[j++] = result[i] + '0';
    }
    final_result[j] = '\0';

    free(result);

    /* Fix memory leak: Allocate "0" instead of returning string literal */
    if (j == 0)
    {
        free(final_result);
        final_result = malloc(2);
        if (!final_result)
            return (NULL);
        final_result[0] = '0';
        final_result[1] = '\0';
    }

    return (final_result);
}

/**
 * main - Entry point. Multiplies two positive numbers.
 * @argc: Number of arguments.
 * @argv: Argument vector (list of arguments).
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
    char *result;

    if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
    {
        printf("Error\n");
        exit(98);
    }

    result = multiply(argv[1], argv[2]);
    if (!result)
    {
        printf("Error\n");
        exit(98);
    }

    printf("%s\n", result);
    free(result);  /* Free allocated memory to fix memory leak */

    return (0);
}

