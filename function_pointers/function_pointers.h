#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h> /* For size_t */

/**
 * print_name - Calls a function to print a name
 * @name: The name to be printed
 * @f: Pointer to a function that prints a name
 */
void print_name(char *name, void (*f)(char *));

/**
 * array_iterator - Executes a function on each element of an array
 * @array: The array to iterate through
 * @size: The size of the array
 * @action: Pointer to a function to apply
 */
void array_iterator(int *array, size_t size, void (*action)(int));

#endif /* FUNCTION_POINTERS_H */

