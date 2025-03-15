#include "dog.h"
#include <stdio.h>

/**
 * print_dog - Prints the details of a struct dog.
 * @d: Pointer to the struct dog to print.
 *
 * Description: If d is NULL, print nothing. If a field is NULL,
 * print (nil) instead.
 */
void print_dog(struct dog *d)
{
    if (d == NULL)
        return;

    /* Print name (handle NULL case) */
    if (d->name == NULL)
        printf("Name: (nil)\n");
    else
        printf("Name: %s\n", d->name);

    /* Print age */
    printf("Age: %f\n", d->age);

    /* Print owner (handle NULL case) */
    if (d->owner == NULL)
        printf("Owner: (nil)\n");
    else
        printf("Owner: %s\n", d->owner);
}

