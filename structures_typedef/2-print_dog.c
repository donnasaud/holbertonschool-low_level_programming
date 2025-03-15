#include "dog.h"
#include <stdio.h>

/**
 * print_dog - Prints a struct dog
 * @d: Pointer to the struct dog
 *
 * Description: This function prints the details of a struct dog.
 * If d is NULL, the function does nothing.
 * If an element is NULL, it prints "(nil)" instead of that element.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	/* Print name, handle NULL case */
	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	/* Print age */
	printf("Age: %f\n", d->age);

	/* Print owner, handle NULL case */
	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}

