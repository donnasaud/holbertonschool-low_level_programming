#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - Creates a new dog with a copy of name and owner
 * @name: The name of the dog
 * @age: The age of the dog
 * @owner: The owner of the dog
 *
 * Return: Pointer to the new dog (dog_t), or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *name_copy, *owner_copy;

	/* Step 1: Allocate memory for the new dog struct */
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	/* Step 2: Allocate memory for name and owner */
	name_copy = malloc(strlen(name) + 1);
	if (name_copy == NULL)
	{
		free(dog);
		return (NULL);
	}

	owner_copy = malloc(strlen(owner) + 1);
	if (owner_copy == NULL)
	{
		free(dog);
		free(name_copy);
		return (NULL);
	}

	/* Step 3: Copy the name and owner strings */
	strcpy(name_copy, name);
	strcpy(owner_copy, owner);

	/* Step 4: Assign values to the struct */
	dog->name = name_copy;
	dog->age = age;
	dog->owner = owner_copy;

	return (dog);
}

