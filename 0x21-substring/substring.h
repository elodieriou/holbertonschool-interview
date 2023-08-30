#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int is_valid(int *word_count, int nb_words);

#endif /* SUBSTRING_H */
