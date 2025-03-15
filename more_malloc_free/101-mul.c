#include "main.h"
#include <unistd.h> /* Add this line */

/**
 * is_number - Checks if a string contains only digits.
 * @s: The string to check.
 *
 * Return: 1 if the string is a number, 0 otherwise.
 */
int is_number(char *s)
{
    int i = 0;

    if (!s || s[0] == '\0') /* If string is NULL or empty */
        return (0);

    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9') /* If character is not a digit */
            return (0);
        i++;
    }
    return (1);
}

/**
 * string_length - Returns the length of a string.
 * @s: The string.
 *
 * Return: Length of the string.
 */
int string_length(char *s)
{
    int len = 0;
    
    while (s[len])
        len++;
    
    return (len);
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
    int len1 = string_length(num1);
    int len2 = string_length(num2);
    int *result;
    char *final_result;
    int i, j, carry, n1, n2, sum;

    /* Allocate memory for result */
    result = calloc(len1 + len2, sizeof(int));
    if (!result)
        return (NULL);

    /* Perform multiplication */
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

    /* Convert result to string */
    final_result = malloc(len1 + len2 + 1);
    if (!final_result)
    {
        free(result);
        return (NULL);
    }

    j = 0;
    for (i = 0; i < len1 + len2; i++)
    {
        if (!(j == 0 && result[i] == 0)) /* Skip leading zeros */
            final_result[j++] = result[i] + '0';
    }
    final_result[j] = '\0';

    free(result);
    return (final_result);
}

/**
 * main - Entry point. Multiplies two positive numbers.
 * @argc: Number of arguments.
 * @argv: Argument vector.
 *
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
    char *result;
    int i;

    /* Validate input arguments */
    if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
    {
        write(1, "Error\n", 6);
        exit(98);
    }

    /* Perform multiplication */
    result = multiply(argv[1], argv[2]);
    if (!result)
    {
        write(1, "Error\n", 6);
        exit(98);
    }

    /* Print result using _putchar */
    for (i = 0; result[i] != '\0'; i++)
        _putchar(result[i]);

    _putchar('\n');
    free(result); /* Free allocated memory */

    return (0);
}

