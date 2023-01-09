#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int is_sandpile_stable(int grid[3][3]);
void copy_grid(int grid1[3][3], int grid2[3][3]);
int topple_sandpile(int grid1[3][3], int grid2[3][3], int i, int j);
int is_grain_stable(int grid1[3][3], int grid2[3][3], int i, int j);
static void print_grid(int grid[3][3]);

#endif /* SANDPILES_H */
