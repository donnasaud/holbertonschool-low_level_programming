#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/* Function to check if input is a valid number */
int is_number(char *str)
{
    while (*str)
    {
        if (!isdigit(*str)) /* Check if it's a digit */
            return (0);
        str++;
    }
    return (1);
}

/* Function to perform string-based multiplication */
char *multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, i, j, carry, n1, n2, sum;
    int *result;
    char *final_result;

    /* Find the lengths of both numbers */
    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;

    /* Allocate space for the product (max length = len1 + len2) */
    result = calloc(len1 + len2, sizeof(int));
    if (!result)
        return (NULL);

    /* Multiply each digit from num1 with each digit from num2 */
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

    /* Convert integer array to string */
    final_result = malloc(len1 + len2 + 1);
    if (!final_result)
    {
        free(result);
        return (NULL);
    }

    /* Copy the numbers into the final result */
    j = 0;
    for (i = 0; i < len1 + len2; i++)
    {
        if (!(j == 0 && result[i] == 0)) /* Skip leading zeros */
            final_result[j++] = result[i] + '0';
    }
    final_result[j] = '\0';

    free(result);
    return (j == 0) ? "0" : final_result; /* If result is empty, return "0" */
}

/* Main function to handle input and call multiplication */
int main(int argc, char *argv[])
{
    char *result;

    /* Ensure exactly 2 arguments are provided */
    if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
    {
        printf("Error\n");
        exit(98);
    }

    /* Perform multiplication */
    result = multiply(argv[1], argv[2]);
    if (!result)
    {
        printf("Error\n");
        exit(98);
    }

    /* Print the result */
    printf("%s\n", result);
    free(result);

    return (0);
}


