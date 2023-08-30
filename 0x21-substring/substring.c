#include "substring.h"

/**
 * is_valid - Function that check whether all words in the array
 * @word_count: the array of words
 * @nb_words: the number of words in the array
 * Return: 1 if is valid substring, 0 otherwise
 */
int is_valid(int *word_count, int nb_words)
{
	int i;

	for (i = 0; i < nb_words; i++)
		if (word_count[i] != 0)
			return (0);
	return (1);
}

/**
 * find_substring - Function that find all valid substring in a string
 * @s: the string to scan
 * @words: the array of words all substring must be a concatenation of string
 * @nb_words: the number of elements in the array words
 * @n: holds the address at which to store the number of elements in the array
 * Return: an allocated array, storing each index in s at which a substring
 * was found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_length = strlen(words[0]), string_length = strlen(s);
	int *result = NULL, result_size = 0, i, j, k, found_word, *temp_word_count;
	char *current_word;
	int *word_count = malloc(nb_words * sizeof(int));

	for (i = 0; i < nb_words; i++)
		word_count[i] = 1;
	for (i = 0; i <= string_length - nb_words * word_length; i++)
	{
		temp_word_count = malloc(nb_words * sizeof(int));
		memcpy(temp_word_count, word_count, nb_words * sizeof(int));
		j = i;
		while (j < i + nb_words * word_length)
		{
			current_word = malloc((word_length + 1) * sizeof(char));
			strncpy(current_word, s + j, word_length);
			current_word[word_length] = '\0';
			found_word = 0;
			for (k = 0; k < nb_words; k++)
				if (temp_word_count[k] > 0 && strcmp(current_word, words[k]) == 0)
				{
					temp_word_count[k]--;
					found_word = 1;
					break;
				}
			free(current_word);
			if (!found_word)
				break;
			j += word_length;
		}
		if (is_valid(temp_word_count, nb_words))
		{
			result = realloc(result, ++result_size * sizeof(int));
			result[result_size - 1] = i;
		}
		free(temp_word_count);
	}
	free(word_count);
	*n = result_size;
	return (result);
}
