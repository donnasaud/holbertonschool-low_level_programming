#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings and returns a new allocated string
 * @s1: First input string
 * @s2: Second input string
 *
 * Return: Pointer to new string, or NULL if allocation fails
 */
char *str_concat(char *s1, char *s2)
{
    char *concat_str;
    int i, j, len1 = 0, len2 = 0;

    /* Handle NULL inputs by treating them as empty strings */
    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    /* Calculate lengths of s1 and s2 */
    while (s1[len1] != '\0')
        len1++;
    while (s2[len2] != '\0')
        len2++;

    /* Allocate memory for new concatenated string */
    concat_str = malloc(sizeof(char) * (len1 + len2 + 1));
    if (concat_str == NULL)
        return (NULL); /* Return NULL if allocation fails */

    /* Copy s1 into concat_str */
    for (i = 0; i < len1; i++)
        concat_str[i] = s1[i];

    /* Copy s2 into concat_str */
    for (j = 0; j < len2; j++, i++)
        concat_str[i] = s2[j];

    concat_str[i] = '\0'; /* Null-terminate the new string */
    return (concat_str);
}

