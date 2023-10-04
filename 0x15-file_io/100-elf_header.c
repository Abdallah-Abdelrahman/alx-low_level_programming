#include "main.h"

/**
 * main - displays the information contained in the ELF header.
 * @ac: ac
 * @av: av
 *
 * Return: 0 as exit status
 */
int main(int ac, char **av)
{
	int fd, bytes, offset;
	char *elf, buf[BUFFER], *magic = "\x7F\x45\x4c\x46";
	Elf64_Ehdr elf_header;


	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Error: no file supplied\n");
		exit(98);
	}
	elf = av[1];
	fd = open(elf, O_RDONLY);
	if (fd < 0)
		error_handler(fd, 0);
	bytes = read(fd, buf, 4);
	if (bytes < 0)
		error_handler(fd, 1);
	buf[bytes] = 0;
	if (_strcmp(magic, buf) != 0)
	{
		close(fd);
		dprintf(STDERR_FILENO,
				"Error: Not an ELF file - it has the wrong magic %s\n", elf);
		exit(98);
	}
	offset = lseek(fd, 0, SEEK_SET);
	if (offset < 0)
		error_handler(fd, 1);
	bytes = read(fd, &elf_header, sizeof(elf_header));
	if (bytes < 0)
		error_handler(fd, 1);
	print_Ehdr(elf_header);
	close(fd);

	return (0);
}
/**
 * error_handler - handle errors
 * @fd: file descriptor
 * @flag: if == 1 close the file,
 * 0 don't close
 */
void error_handler(int fd, int flag)
{
	close(fd);
	dprintf(STDERR_FILENO, "Error: faied to read elf\n");
	if (flag)
		exit(98);
}

/**
 * print_Ehdr - print ELF header
 * @elf_header: the elf header
 */
void print_Ehdr(Elf64_Ehdr elf_header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		if (i)
			printf(" ");
		printf("%02x", elf_header.e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             %s\n",
	get_class(elf_header));
	printf("  Data:                              %s\n",
	get_data(elf_header));
	printf("  Version:                           %d (current)\n",
	elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
	get_osabi(elf_header));
	printf("  ABI Version:                       %d\n",
	(int)elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
	get_type(elf_header));
	printf("  Entry point address:               0x%lx\n",
	(unsigned long int)elf_header.e_entry);
}

/**
 * get_version - get the elf version
 * @elf: elf header
 *
 * Return: string corresponding to the version
 */
char *get_version(Elf64_Ehdr elf)
{
	return (elf.e_ident[EI_VERSION] == EV_CURRENT
			? "1 (current)"
			: "0 (invalid)");
}
/**
 * get_data - get the elf data
 * @elf: elf header
 *
 * Return: string corresponding to the data
 */
char *get_data(Elf64_Ehdr elf)
{
	switch (elf.e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			return ("2's complement, little endian");
		case ELFDATA2MSB:
			return ("2's complement, big endian");
		default:
			return ("<unknown: 53>");
	}
}

/**
 * get_class - get the elf class
 * @elf: elf header
 *
 * Return: string corresponding to the class
 */
char *get_class(Elf64_Ehdr elf)
{
	switch (elf.e_ident[EI_CLASS])
	{
		case ELFCLASS64:
			return ("ELF64");
		case ELFCLASS32:
			return ("ELF32");
		default:
			return ("<unknown: 53>");
	}
}
/**
 * get_type - get the elf type
 * @elf: elf header
 *
 * Return: string corresponding to the type
 */
char *get_type(Elf64_Ehdr elf)
{
	switch (elf.e_type)
	{
		case ET_REL:
			return ("REL (Relocatable file)");
		case ET_EXEC:
			return ("EXEC (Executable file)");
		case ET_DYN:
			return ("DYN (Shared object file)");
		case ET_CORE:
			return ("CORE (Core file)");
		default:
			return ("<unknown: 53>");
	}
}

/**
 * get_osabi - get the elf OS/ABI
 * @elf: elf header
 *
 * Return: string corresponding to the OS/ABI
 */
char *get_osabi(Elf64_Ehdr elf)
{
	switch (elf.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			return ("UNIX - System V");
		case ELFOSABI_SOLARIS:
			return ("UNIX - Solaris");
		case ELFOSABI_NETBSD:
			return ("UNIX - NetBSD");
		case ELFOSABI_LINUX:
			return ("UNIX - GNU");
#if 0
		case ELFOSABI_HPUX:
			return ("UNIX - HP-UX");
		case ELFOSABI_FREEBSD:
			return ("UNIX - FreeBSD");
		case ELFOSABI_TRU64:
			return ("UNIX - TRU64");
		case ELFOSABI_ARM:
			return ("UNIX - ARM architecture");
		case ELFOSABI_STANDALONE:
			return ("UNIX - Stand-alone (embedded)");
#endif
		default:
			return ("<unknown: 53>");
	}
}
/**
 * _strcmp - compares 2 strings
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: 0 if s1 & s2 are equal,
 * a negative value if s1 < s2
 * a positive value if s1 > s2
 *
 */
int _strcmp(char *s1, char *s2)
{
	int ret = 0;

	for (; *s1 && *s2; s1++, s2++)
	{
		if (*s1 != *s2)
		{
			ret = *s1 - *s2;
			break;
		}
	}

	return (ret);
}
