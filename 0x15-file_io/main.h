#ifndef HEADER
#define HEADER
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFER 1024
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void print_error(char *str, char *file, int stat);


#endif /* HEADER */
