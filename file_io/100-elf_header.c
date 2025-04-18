#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

/**
 * print_error - Print an error message and exit
 * @msg: message to print
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Reads and prints ELF header information
 * @filename: path to the ELF file
 */
void print_elf_header(const char *filename)
{
	int fd, i;
	ssize_t bytes;
	Elf64_Ehdr header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Cannot open file");

	bytes = read(fd, &header, sizeof(header));
	if (bytes != sizeof(header))
		print_error("Cannot read ELF header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", header.e_ident[i], i < EI_NIDENT - 1 ? ' ' : '\n');

	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
		case ELFCLASS32: printf("ELF32\n"); break;
		case ELFCLASS64: printf("ELF64\n"); break;
		default: printf("<unknown: %x>\n", header.e_ident[EI_CLASS]); break;
	}

	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
		case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
		case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
		default: printf("<unknown: %x>\n", header.e_ident[EI_DATA]); break;
	}

	printf("  Version:                           ");
	if (header.e_ident[EI_VERSION] == EV_CURRENT)
		printf("%d (current)\n", EV_CURRENT);
	else
		printf("%d\n", header.e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
		default: printf("<unknown: %x>\n", header.e_ident[EI_OSABI]); break;
	}

	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (header.e_type)
	{
		case ET_NONE: printf("NONE (None)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default: printf("<unknown: %x>\n", header.e_type); break;
	}

	printf("  Entry point address:               ");
	if (header.e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)header.e_entry);
	else
		printf("%#lx\n", (unsigned long)header.e_entry);

	close(fd);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
		exit(98);
	}

	print_elf_header(argv[1]);
	return (0);
}

