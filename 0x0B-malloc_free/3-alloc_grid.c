#include "main.h"
/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: columns
 * @height: rows
 *
 * Return: pointer to 2 dimensional array,
 * NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid, j, i = 0;

	if ((width || height) <= 0)
		return (0);

	grid = malloc(sizeof(int) * width * height);
	if (!grid)
		return (0);

	for (; i < height; i++)
	{
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
