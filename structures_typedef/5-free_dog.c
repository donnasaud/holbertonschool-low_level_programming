#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees memory allocated for a dog_t struct.
 * @d: Pointer to the dog_t structure to be freed.
 *
 * Description: Frees dynamically allocated memory of `name` and `owner`,
 * then frees the structure itself.
 */
void free_dog(dog_t *d)
{
    if (d == NULL)
        return;

    if (d->name)
        free(d->name);

    if (d->owner)
        free(d->owner);

    free(d);
}

