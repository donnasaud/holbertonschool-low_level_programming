#ifndef DOG_H
#define DOG_H

#include <stdio.h>

/**
 * struct dog - Structure for a dog
 * @name: Pointer to the dog's name
 * @age: Dog's age (float)
 * @owner: Pointer to the owner's name
 *
 * Description: This structure stores information about a dog.
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d); /* Add the prototype */

#endif /* DOG_H */

