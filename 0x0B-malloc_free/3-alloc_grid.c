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
	int **grid, j = 0, i = 0;

	if (width <= 0 || height <= 0)
		return (0);

	grid = malloc(sizeof(*grid) * height);

	if (!grid)
	{
		free(grid);
		return (0);
	}

	for (; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);
		if (!grid[i])
		{
			for (; j < i; j++)
				free(grid[j]);
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
