#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <stdint.h>

/* Byte swap helpers */
unsigned short swap16(unsigned short val)
{
	return ((val << 8) | (val >> 8));
}

uint32_t swap32(uint32_t val)
{
	return (((val >> 24) & 0xff) |
		((val << 8) & 0xff0000) |
		((val >> 8) & 0xff00) |
		((val << 24) & 0xff000000));
}

uint64_t swap64(uint64_t val)
{
	return (((val >> 56) & 0xff) |
		((val << 40) & 0xff000000000000) |
		((val << 24) & 0xff0000000000) |
		((val << 8) & 0xff00000000) |
		((val >> 8) & 0xff000000) |
		((val >> 24) & 0xff0000) |
		((val >> 40) & 0xff00) |
		((val << 56) & 0xff00000000000000));
}

/* Print ELF class, data, version, OS/ABI, ABI version */
void print_ident_info(Elf64_Ehdr *header)
{
	printf("  Class:                             ");
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);

	printf("  Data:                              ");
	if (header->e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", header->e_ident[EI_DATA]);

	printf("  Version:                           ");
	if (header->e_ident[EI_VERSION] == EV_CURRENT)
		printf("1 (current)\n");
	else
		printf("%d\n", header->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
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
		printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n",
	       header->e_ident[EI_ABIVERSION]);
}

/* Print ELF type */
void print_elf_type(unsigned short e_type)
{
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

/* Print ELF header: Magic, class, data, version, type, entry */
void print_elf_header(Elf64_Ehdr *header)
{
	int i, big;
	uint64_t e_entry;
	unsigned short e_type;

	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header->e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
		else
			printf("\n");
	}

	print_ident_info(header);

	big = (header->e_ident[EI_DATA] == ELFDATA2MSB);
	e_type = header->e_type;
	e_entry = header->e_entry;

	if (big)
	{
		e_type = swap16(e_type);
		if (header->e_ident[EI_CLASS] == ELFCLASS32)
			e_entry = swap32((uint32_t)e_entry);
		else
			e_entry = swap64(e_entry);
	}

	print_elf_type(e_type);

	printf("  Entry point address:               ");
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", (unsigned long)e_entry);
}

/* Entry point */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t r;
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
	r = read(fd, &header, sizeof(header));
	if (r != sizeof(header))
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

