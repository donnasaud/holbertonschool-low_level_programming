#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own function.
 * @argc: The number of arguments.
 * @argv: An array of argument strings.
 *
 * Return: 0 on success, 1 on incorrect argument count, 2 on negative bytes.
 */
int main(int argc, char *argv[])
{
	int num_bytes, i;
	unsigned char *func_ptr;

	/* Step 1: Validate the number of arguments */
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	/* Step 2: Convert argument to integer */
	num_bytes = atoi(argv[1]);

	/* Step 3: Check for negative bytes */
	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	/* Step 4: Get the address of main as a function pointer */
	func_ptr = (unsigned char *) main;

	/* Step 5: Print the opcodes in hexadecimal format */
	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", func_ptr[i]);

		/* Step 6: Add a space after each byte except the last */
		if (i < num_bytes - 1)
			printf(" ");
	}

	/* Step 7: Print newline at the end */
	printf("\n");

	return (0);
}

