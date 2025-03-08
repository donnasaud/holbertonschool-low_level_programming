#include "main.h"
#include <stdio.h>

/**
 * main - Entry point to test add function
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int n;

    n = add(89, 9); /* Call the add function */
    printf("%d\n", n); /* Print result */
    return (0);
}

