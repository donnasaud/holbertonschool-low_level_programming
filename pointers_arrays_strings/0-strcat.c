#include "main.h"
#include <stdio.h>  /* For testing purposes */

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;

    while (dest[i] != '\0')
        i++;

    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';

    return (dest);
}

/* Temporary main function for testing */
int main(void)
{
    char s1[98] = "Hello ";
    char s2[] = "World!\n";
    char *ptr;

    printf("%s\n", s1);
    printf("%s", s2);

    ptr = _strcat(s1, s2);

    printf("%s", s1);
    printf("%s", s2);
    printf("%s", ptr);

    return (0);
}

