#include "main.h"

/**
 * print_number - Prints an integer using _putchar.
 * @n: The integer to print.
 */
void print_number(int n)
{
    unsigned int num;

    /* Handle negative numbers */
    if (n < 0)
    {
        _putchar('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    /* Recursively print digits */
    if (num / 10)
        print_number(num / 10);

    /* Print the last digit */
    _putchar((num % 10) + '0');
}

