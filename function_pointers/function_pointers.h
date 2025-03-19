#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h> /* For NULL */

/**
 * print_name - Calls a function to print a name
 * @name: The name to be printed
 * @f: Pointer to a function that prints a name
 */
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTERS_H */

