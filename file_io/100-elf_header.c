#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <stdint.h>

/**
 * swap16 - Swaps byte order of a 16-bit value
 * @val: The 16-bit value to swap
 * Return: The byte-swapped value
 */
unsigned short swap16(unsigned short val)
{
	return ((val << 8) | (val >> 8));
}

/**
 * swap32 - Swaps byte order of a 32-bit value
 * @val: The 32-bit value to swap
 * Return: The byte-swapped value
 */
uint32_t swap32(uint32_t val)
{
	return ((val >> 24) & 0xff) |
		((val << 8) & 0xff0000) |
		((val >> 8) & 0xff00) |
		((val << 24) & 0xff000000);
}

/**
 * swap64 - Swaps byte order of a 64-bit value
 * @val: The 64-bit value to swap
 * Return: The byte-swapped value
 */
uint64_t swap64(uint64_t val)
{
	return ((val >> 56) & 0xff) |
		((val << 40) & 0xff000000000000) |
		((val << 24) & 0xff0000000000) |
		((val << 8) & 0xff00000000) |
		((val >> 8) & 0xff000000) |
		((val >> 24) & 0xff0000) |
		((val >> 40) & 0xff00) |
		((val << 56) & 0xff00000000000000);
}

/**
 * print_ident_info - Prints ELF identification details
 * @e_ident: The ELF identification array
 */
void print_ident_info(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
		else
			printf("\n");
	}

	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}

	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}

	printf("  Version:                           ");
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf("1 (current)\n");
	else
		printf("%d\n", e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_elf_type - Prints the ELF file type
 * @e_type: The ELF type field
 * @is_big_endian: 1 if big endian, 0 if little endian
 */
void print_elf_type(unsigned short e_type, int is_big_endian)
{
	if (is_big_endian)
		e_type = swap16(e_type);

	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_elf_header - Prints the full ELF header details
 * @header: Pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int is_big_endian;
	uint64_t e_entry;

	print_ident_info(header->e_ident);
	is_big_endian = (header->e_ident[EI_DATA] == ELFDATA2MSB);
	print_elf_type(header->e_type, is_big_endian);

	printf("  Entry point address:               ");
	e_entry = header->e_entry;
	if (is_big_endian)
	{
		if (header->e_ident[EI_CLASS] == ELFCLASS32)
			e_entry = swap32((uint32_t)e_entry);
		else
			e_entry = swap64(e_entry);
	}

	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", (unsigned long)e_entry);
}

/**
 * main - Entry point, displays the ELF header of a file
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t bytes_read;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(98);
	}

	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read != sizeof(header))
	{
		fprintf(stderr, "Error reading ELF header\n");
		close(fd);
		exit(98);
	}

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}

	print_elf_header(&header);
	close(fd);
	return (0);
}

