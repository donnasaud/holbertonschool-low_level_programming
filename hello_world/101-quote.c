#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints "and that piece of art is useful"
 *              - Dora Korpar, 2015-10-19 to standard error.
 *              Does not use printf or puts.
 * Return: Always returns 1 (error)
 */
int main(void)
{
	char message[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(2, message, 59);

	return (1);
}

