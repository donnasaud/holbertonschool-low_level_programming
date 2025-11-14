#include <stdio.h>
#include <stdlib.h>

/**
 * main - Outputs the product of two numbers, followed by a newline.
 * @argc: The count of arguments provided to the program.
 * @argv: An array of pointers to the argument strings.
 * Return: 0 if the program receives two arguments.
 *         1 if the program does not receive two arguments.
*/

int main(int argc, char *argv[])
{
int num1, num2, prod;

if (argc != 3)
{
printf("Error\n");
return (1);
}

num1 = atoi(argv[1]);
num2 = atoi(argv[2]);
prod = num1 *num2;

printf("%d\n", prod);

return (0);
}
