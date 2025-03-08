#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number.
 * @n: The input number.
 *
 * Return: The last digit.
 */
int print_last_digit(int n)
{
    int last_digit;

    /* Get the absolute value of the last digit */
    last_digit = n % 10;
    if (last_digit < 0)
        last_digit *= -1;

    _putchar(last_digit + '0'); /* Convert to char and print */
    return (last_digit);
}

