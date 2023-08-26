#include "main.h"

/**
 * print_buffer - prints buffer
 * @b: pointer
 * @size: size
 */
void print_buffer(char *b, int size)
{
	int i = 0, j, k = 0;

	if (size <= 0)
		printf("\n");

	for (; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 5; j++)
		{
			char h_00 = b[(j + k) * 2];
			char h_01 = b[((j + k) * 2) + 1];
			printf("%02x%02x ", h_00, h_01);
		}

		printf("\n");
		k += 5;
	}


}
