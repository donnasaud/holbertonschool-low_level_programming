#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - Calculates the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination buffer.
 * @src: The source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

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
	name_copy = malloc(_strlen(name) + 1);
	if (name_copy == NULL)
	{
		free(dog);
		return (NULL);
	}

	owner_copy = malloc(_strlen(owner) + 1);
	if (owner_copy == NULL)
	{
		free(dog);
		free(name_copy);
		return (NULL);
	}

	/* Step 3: Copy the name and owner strings using our own function */
	_strcpy(name_copy, name);
	_strcpy(owner_copy, owner);

	/* Step 4: Assign values to the struct */
	dog->name = name_copy;
	dog->age = age;
	dog->owner = owner_copy;

	return (dog);
}

