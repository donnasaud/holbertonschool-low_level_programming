#ifndef DOG_H
#define DOG_H

#include <stdio.h>

/**
 * struct dog - Structure for a dog's basic info
 * @name: Pointer to the dog's name
 * @age: Dog's age as a float
 * @owner: Pointer to the owner's name
 *
 * Description: This structure stores information about a dog,
 * including its name, age, and owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */

