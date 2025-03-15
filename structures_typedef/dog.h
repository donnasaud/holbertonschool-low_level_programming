#ifndef DOG_H
#define DOG_H

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

/* Function prototype */
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */

