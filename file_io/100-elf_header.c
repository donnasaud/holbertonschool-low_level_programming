#include "elf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

/**
 * swap16 - Swap endianness of a 16-bit integer
 * @val: value to swap
 * Return: swapped value
 */
uint16_t swap16(uint16_t val)
{
	return ((val << 8) | (val >> 8));
}

/**
 * swap64 - Swap endianness of a 64-bit integer
 * @val: value to swap
 * Return: swapped value
 */
uint64_t swap64(uint64_t val)
{
	return ((val << 56) |
		((val & 0xFF00) << 40) |
		((val & 0xFF0000) << 24) |
		((val & 0xFF000000) << 8) |
		((val & 0xFF00000000) >> 8) |
		((val & 0xFF0000000000) >> 24) |
		((val & 0xFF000000000000) >> 40) |
		(val >> 56));
}

/**
 * print_error - Print error and exit
 * @msg: Error message
 */
void print_error(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

/**
 * print_magic - Print ELF magic bytes
 * @e_ident: ELF identification array
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * print_class - Print ELF class
 * @e_ident: ELF identification array
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

/**
 * print_data - Print ELF data encoding
 * @e_ident: ELF identification array
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
}

/**
 * print_version - Print ELF version
 * @e_ident: ELF identification array
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * print_osabi - Print ELF OS/ABI
 * @e_ident: ELF identification array
 */
void print_osabi(unsigned char *e_ident)
{
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
}

/**
 * print_abiversion - Print ELF ABI version
 * @e_ident: ELF identification array
 */
void print_abiversion(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Print ELF file type
 * @e_type: File type
 * @is_big_endian: 1 if file is big endian
 */
void print_type(uint16_t e_type, int is_big_endian)
{
	if (is_big_endian)
		e_type = swap16(e_type);

	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Print ELF entry point
 * @e_entry: Entry point
 * @is_big_endian: 1 if file is big endian
 * @elf_class: ELF class
 */
void print_entry(uint64_t e_entry, int is_big_endian, int elf_class)
{
	if (is_big_endian)
		e_entry = swap64(e_entry);

	printf("  Entry point address:               ");
	if (elf_class == ELFCLASS32)
		printf("0x%x\n", (uint32_t)e_entry);
	else
		printf("0x%lx\n", e_entry);
}

/**
 * main - Displays the ELF header info
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, exits with 98 on failure
 */
int main(int argc, char **argv)
{
	int fd;
	ssize_t bytes_read;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(strerror(errno));

	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read != sizeof(header))
	{
		close(fd);
		print_error("Failed to read ELF header");
	}

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		close(fd);
		print_error("Not an ELF file");
	}

	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abiversion(header.e_ident);
	print_type(header.e_type, header.e_ident[EI_DATA] == ELFDATA2MSB);
	print_entry(header.e_entry, header.e_ident[EI_DATA] == ELFDATA2MSB,
		header.e_ident[EI_CLASS]);

	close(fd);
	return (0);
}

