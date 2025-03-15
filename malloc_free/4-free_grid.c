#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a 2D array previously created by alloc_grid
 * @grid: The address of the 2D grid
 * @height: Number of rows in the grid
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

