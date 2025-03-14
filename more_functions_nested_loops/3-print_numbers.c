#include "main.h"

/**
 * print_numbers - Prints numbers from 0 to 9
 * 
 * Description: Uses _putchar to print digits in a loop
 * followed by a newline.
 */
void print_numbers(void)
{
    char digit;

    for (digit = '0'; digit <= '9'; digit++)  /* Loop from '0' to '9' */
        _putchar(digit);

    _putchar('\n');  /* Print newline */
}

