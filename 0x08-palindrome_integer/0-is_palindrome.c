#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer
 * is a palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed_n = 0;
	unsigned long number = n;

	while (number != 0)
	{
		reversed_n = (reversed_n * 10) + number % 10;
		number = number / 10;
	}
	if (n == reversed_n)
		return (1);
	return (0);
}
