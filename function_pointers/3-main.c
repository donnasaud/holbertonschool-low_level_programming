#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for the calculator program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98/99/100 on error
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*op_func)(int, int);

	/* Validate argument count */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	/* Convert arguments to integers */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	/* Get the appropriate function */
	op_func = get_op_func(argv[2]);
	if (!op_func)
	{
		printf("Error\n");
		exit(99);
	}

	/* Perform calculation and print result */
	result = op_func(num1, num2);
	printf("%d\n", result);

	return (0);
}

