#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - Creates a new dog with a copy of name and owner.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: Pointer to the newly created dog_t struct, or NULL if it fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *name_copy, *owner_copy;

	/* Allocate memory for the new dog struct */
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	/* Allocate memory for name and owner */
	name_copy = malloc(strlen(name) + 1);
	owner_copy = malloc(strlen(owner) + 1);
	if (name_copy == NULL || owner_copy == NULL)
	{
		free(dog);
		free(name_copy);
		free(owner_copy);
		return (NULL);
	}

	/* Copy name and owner */
	strcpy(name_copy, name);
	strcpy(owner_copy, owner);

	/* Assign values to struct */
	dog->name = name_copy;
	dog->age = age;
	dog->owner = owner_copy;

	return (dog);
}

