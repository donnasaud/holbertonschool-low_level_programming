#include <stdio.h>
#include <stdlib.h>

/**
 * main - Outputs the sum of positive numbers, followed by a newline.
 * @argc: The count of arguments provided to the program.
 * @argv: An array of pointers to the argument strings.
 *
 * Return: 1 if any of the numbers contain non-digit symbols.
 *         Otherwise, returns 0.
*/
int main(int argc, char *argv[])
{
int num, digit, sum = 0;

for (num = 1; num < argc; num++)
{
for (digit = 0; argv[num][digit]; digit++)
{
if (argv[num][digit] < '0' || argv[num][digit] > '9')
{
printf("Error\n");
return (1);
}
}

sum += atoi(argv[num]);
}

printf("%d\n", sum);

return (0);
}
