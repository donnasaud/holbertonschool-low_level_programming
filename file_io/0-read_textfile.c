#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: Name of the file to read.
 * @letters: Number of letters it should read and print.
 *
 * Return: Actual number of letters it could read and print.
 *         0 if the file can't be opened or read, or if write fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rcount, wcount;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	rcount = read(fd, buffer, letters);
	if (rcount == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	wcount = write(STDOUT_FILENO, buffer, rcount);
	if (wcount == -1 || wcount != rcount)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);
	return (wcount);
}

