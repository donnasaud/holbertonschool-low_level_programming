#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error - prints error message and exits with 98
 * @msg: message to print
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * print_elf_header - prints ELF header information
 * @ehdr: pointer to ELF header
 */
void print_elf_header(Elf64_Ehdr *ehdr)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", ehdr->e_ident[i], i < EI_NIDENT - 1 ? ' ' : '\n');

	printf("  Class:                             ");
	switch (ehdr->e_ident[EI_CLASS])
	{
		case ELFCLASS32: printf("ELF32\n"); break;
		case ELFCLASS64: printf("ELF64\n"); break;
		default:         printf("<unknown: %x>\n", ehdr->e_ident[EI_CLASS]);
	}

	printf("  Data:                              ");
	switch (ehdr->e_ident[EI_DATA])
	{
		case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
		case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
		default:          printf("<unknown: %x>\n", ehdr->e_ident[EI_DATA]);
	}

	printf("  Version:                           %d", ehdr->e_ident[EI_VERSION]);
	if (ehdr->e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");

	printf("  OS/ABI:                            ");
	switch (ehdr->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:     printf("UNIX - System V\n"); break;
		case ELFOSABI_NETBSD:   printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_SOLARIS:  printf("UNIX - Solaris\n"); break;
		default:                printf("<unknown: %x>\n", ehdr->e_ident[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (ehdr->e_type)
	{
		case ET_NONE: printf("NONE (None)\n"); break;
		case ET_REL:  printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN:  printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default:      printf("<unknown: %x>\n", ehdr->e_type);
	}

	printf("  Entry point address:               %#lx\n", (unsigned long)ehdr->e_entry);
}

/**
 * main - displays ELF header info of a given file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	int fd;
	ssize_t r;
	Elf64_Ehdr ehdr;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Cannot open file");

	r = read(fd, &ehdr, sizeof(ehdr));
	if (r != sizeof(ehdr))
	{
		close(fd);
		print_error("Failed to read ELF header");
	}

	if (ehdr.e_ident[EI_MAG0] != ELFMAG0 || ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
		ehdr.e_ident[EI_MAG2] != ELFMAG2 || ehdr.e_ident[EI_MAG3] != ELFMAG3)
	{
		close(fd);
		print_error("Not an ELF file");
	}

	print_elf_header(&ehdr);
	close(fd);
	return (0);
}

