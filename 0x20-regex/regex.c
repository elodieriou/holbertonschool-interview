#include "regex.h"

/**
 * regex_match - function that checks whether a given pattern matches
 * a given string
 * @str: the string to scan
 * @pattern: the regular expression
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return (1);

	if (*str != '\0' && (*str == *pattern || *pattern == '.'))
	{
		if (*(pattern + 1) == '*')
		{
			if (regex_match(str, pattern + 2))
				return (1);
			return (regex_match(str + 1, pattern));
		} else
			return (regex_match(str + 1, pattern + 1));
	} else if (*(pattern + 1) == '*')
		return (regex_match(str, pattern + 2));

	return (0);
}
