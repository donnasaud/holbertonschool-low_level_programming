#include <stdio.h>

/**
 * main - Dummy keygen that prints a test key
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}

	printf("123456\n"); /* Replace this with real keygen logic later */
	return (0);
}

