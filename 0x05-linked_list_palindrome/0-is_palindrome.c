#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	if (*head == NULL)
		return (1);

	return (is_palindrome_recursive(head, *head));
}

/**
 * is_palindrome_recursive - checks if a singly linked list is a palindrome
 * 		with recursion
 * @left: pointer to left of list
 * @right: pointer to right of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome_recursive(listint_t **left, listint_t *right)
{
	if (right->next)
	{
		if (is_palindrome_recursive(left, right->next))
			(*left) = (*left)->next;
		else
			return (0);
	}
	if ((*left)->n == right->n)
		return (1);

	return (0);
}
