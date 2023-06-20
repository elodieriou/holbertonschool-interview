#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_top_down(int *array, int *output, size_t start, size_t mid, size_t end);
void merge_print_step(int *array, int *output, size_t start, size_t mid, size_t end);
void merge_recursion(int *array, int *output, size_t start, size_t end);
void merge_sort(int *array, size_t size);

#endif /* SORT_H */
