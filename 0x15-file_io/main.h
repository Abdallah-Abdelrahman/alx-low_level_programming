#ifndef HEADER
#define HEADER
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <elf.h>
#define BUFFER 1024
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void read_write(char *from, char *to, int fd_from, int fd_to);
int close_fd(int fd);
int _strcmp(char *s1, char *s2);
void print_Ehdr(Elf64_Ehdr);
char *get_type(Elf64_Ehdr elf);
char *get_osabi(Elf64_Ehdr elf);
void error_handler(int fd, int flag);
#endif /* HEADER */
