#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Prints an error message and exits with given code
 * @code: Exit code
 * @msg: Error message
 * @file: Filename to include in message (if any)
 */
void error_exit(int code, const char *msg, const char *file)
{
	if (file && *file)
		dprintf(STDERR_FILENO, "%s %s\n", msg, file);
	else
		dprintf(STDERR_FILENO, "%s\n", msg);
	exit(code);
}

/**
 * main - Copies contents of one file to another
 * @ac: Argument count
 * @av: Argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[BUFFER_SIZE];

	if (ac != 3)
		error_exit(97, "Usage: cp file_from file_to", "");

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file", av[1]);

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to", av[2]);
	}

	while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to", av[2]);
		}
	}
	if (r == -1)
		error_exit(98, "Error: Can't read from file", av[1]);

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd", av[1]);
	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd", av[2]);

	return (0);
}

