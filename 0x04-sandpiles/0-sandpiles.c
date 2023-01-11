#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, topple;
	int grid[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] = grid1[i][j] + grid2[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid[i][j];

	while (is_sandpile_stable(grid) == 0)
	{
		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid[i][j] > 3)
				{
					topple = topple_sandpile(grid1, grid, i, j);
					grid1[i][j] -= topple;
				}
			}
		}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid[i][j] = grid1[i][j];
	}
}

/**
 * topple_sandpile - Function that topple a sandpile
 * @grid1: the initial grid
 * @grid2: the grid traversal
 * @i: row index of grid
 * @j: column index of grid
 * Return: the number of grain to remove
 */
int topple_sandpile(int grid1[3][3], int grid2[3][3], int i, int j)
{
	int count = 0;

	if (i > 0)
		count += is_grain_stable(grid1, grid2, i - 1, j);
	else
		count += 1;

	if (i < 2)
		count += is_grain_stable(grid1, grid2, i + 1, j);
	else
		count += 1;

	if (j > 0)
		count += is_grain_stable(grid1, grid2, i, j - 1);
	else
		count += 1;

	if (j < 2)
		count += is_grain_stable(grid1, grid2, i, j + 1);
	else
		count += 1;

	return (count);
}

/**
 * is_grain_stable - Function that check if a grain is stable
 * @grid1: the initial grid
 * @grid2: the grid traversal
 * @i: row index of grid
 * @j: column index of grid
 * Return: 1 if stable, 0 otherwise
 */
int is_grain_stable(int grid1[3][3], int grid2[3][3], int i, int j)
{
	if (grid2[i][j] < 4)
	{
		grid1[i][j]++;
		return (1);
	}
	return (0);
}

/**
 * is_sandpile_stable - Function that check if a sandpiles is stable
 * @grid: a sandpile
 * Return: 1 if is stable, 0 otherwise
 */
int is_sandpile_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
