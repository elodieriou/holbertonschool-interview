#include "palindrome.h"

/**
 * is_palindrome - function that check if an integer is a palindrome
 * @n: the number checked
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reminder, reversed = 0, num = n;

	while (num != 0)
	{
		reminder = num % 10;
		reversed = reversed * 10 + reminder;
		num = num / 10;
	}

	return reversed == n;
}
