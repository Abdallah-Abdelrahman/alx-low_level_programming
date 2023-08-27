#include "main.h"

/**
 * print_buffer - prints buffer
 * @b: pointer
 * @size: size
 */
void print_buffer(char *b, int size)
{
	int i = 0, k = 0, j;

	if (size <= 0)
		printf("\n");

	for (; i < size; i += 10, k += 5)
	{
		printf("%08x: ", i);

		for (j = 0; j < 5; j++)
		{
			char h_00 = b[(j + k) * 2];
			char h_01 = b[((j + k) * 2) + 1];

			if ((j + k) * 2 < size)
				printf("%02x%02x ", h_00, h_01);
			else
				printf("%2c%2c ", 32, 32);
		}
		printable_10b(i, b, size);
		printf("\n");
	}
}

/**
 * printable_10b - print 10 bytes of buffer for each line
 * @index: current index of buffer
 * @buff: buffer
 * @size: size of buffer
 */
void printable_10b(int index, char *buff, int size)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i + index + 1 > size)
			break;
		switch (buff[i + index])
		{
			case '\0': case '\1': case '\2': case '\3':
			case '\4': case '\5': case '\6': case '\7':
			case '\n':
				printf(".");
				break;
			default:
				printf("%c", buff[i + index]);
		}
	}
}
