#include <stdio.h>

/**
 * main - prints the program name
 * @argc: argument count (not used)
 * @argv: argument vector (array of strings)
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void)argc; /* Unused parameter */

	printf("%s\n", argv[0]);
	return (0);
}

