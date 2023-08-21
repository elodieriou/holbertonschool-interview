#include "regex.h"

int regex_match(char const *str, char const *pattern) {
	if (*str == '\0' && *pattern == '\0') {
		return 1;
	}

	if (*str != '\0' && (*str == *pattern || *pattern == '.')) {
		if (*(pattern + 1) == '*') {
			// Case 1: '*' matches zero occurrences of the preceding character
			if (regex_match(str, pattern + 2)) {
				return (1);
			}
			// Case 2: '*' matches one or more occurrences of the preceding character
			return (regex_match(str + 1, pattern));
		} else {
			return (regex_match(str + 1, pattern + 1));
		}
	} else if (*(pattern + 1) == '*') {
		// Handle the '*' operator when there's no match in the current characters
		return (regex_match(str, pattern + 2));
	}

	return (0);
}
