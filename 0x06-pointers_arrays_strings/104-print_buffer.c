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

	/**
	 * the problem is, how to get it from character to decimal (00)
	 * A: if it's divisble in the first place, than it's character (solved)
	 * after you get it, compare it against this range (0 - 31) (01)
	 * on success print dot. (02)
	 * on failure print the character (03)
	 */
	for (i = 0; i < 10; i++)
	{
		if (i + index + 1 > size)
			break;
		if (buff[i + index] / 10 && buff[i + index] != '\n')
		{
			printf("%c", buff[i + index]);
		}
		else
		{
			printf(".");
		}
	}
}
