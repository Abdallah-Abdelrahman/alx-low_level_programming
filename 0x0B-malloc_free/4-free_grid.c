#include "main.h"

/**
 * free_grid - frees a 2 dimensional grid
 * @grid: array of pointers to integer
 * @height: number of rows in grid
 *
 */
void free_grid(int **grid, int height)
{
	int i = 0;

	for (; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
