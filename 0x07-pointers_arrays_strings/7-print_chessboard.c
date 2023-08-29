#include "main.h"

/**
 * print_chessboard - prints the chessboard.
 * @a: pointer to array of 8 chars
 */
void print_chessboard(char (*a)[8])
{
	int i = 0, j;

	for (; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}
