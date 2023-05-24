#include "holberton.h"

/**
 * _isdigit - function that checks if the argument is a number
 * @c: the argument
 * Return: 1 if is a number, 0 otherwise
 */
int _isdigit(char *c)
{
	while (*c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}

	return (1);
}

/**
 * print_error - function that print the error message
 * @str: the message to print
 * Return: Nothing
 */
void print_error(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}


/**
 * _strlen - function that calculates the length of a string
 * @str: the string
 * Return: the length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}

/**
 * multiply - function that computes the product of infinite numbers
 * @str1: the argument with number 1
 * @str2: the argument with number 2
 * Return: Nothing
 */

void multiply(char *str1, char *str2)
{
	int i, j, num1, num2, carry;
	int len1 = _strlen(str1);
	int len2 = _strlen(str2);
	int total = len1 + len2;
	int *res = malloc(sizeof(int) * total);

	if (res == NULL)
		return;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		num1 = str1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			num2 = str2[j] - '0';
			res[i + j] += num1 * num2 + carry;
			carry = res[i + j] / 10;
			res[i + j] %= 10;
		}
		if (carry > 0)
			res[i + j] %= 10;
	}

	for (i = 0; i < total - 1; i++)
		_putchar(res[i] + '0');
	_putchar('\n');

	free(res);
}

/**
 * main - Entry point
 * @argc: the number of arguments
 * @argv: the value of arguments
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	char *num1 = argv[1];
	char *num2 = argv[2];

	if (argc != 3 || _isdigit(num1) == 0 || _isdigit(num2) == 0)
	{
		print_error("Error");
		exit(98);
	}

	multiply(num1, num2);
	return (0);
}
