#include "main.h"

/**
 * print_alphabet - prints the alphabet in lowercase, followed by a new line
 */
void print_alphabet(void)
{
    char c;

    for (c = 'a'; c <= 'z'; c++) /* Loop through lowercase letters */
        _putchar(c); /* Print each letter */

    _putchar('\n'); /* Print newline */
}

