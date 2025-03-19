#include "function_pointers.h"

/**
 * print_name - Calls a function to print a name
 * @name: The name to be printed
 * @f: Pointer to a function that prints a name
 *
 * Description: This function takes a name and a function pointer,
 * then calls the function with the name as an argument.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL) /* Check for NULL */
		return;

	f(name); /* Call the function pointer */
}

