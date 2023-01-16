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
	listint_t *h = *head;
	listint_t *tab = *head;
	int lenght = 0, index = 0;
	int tab_head[100];
	int tab_reversed_head[100];

	if (head == NULL)
		return (1);

	/*calculate the lenght of the singly list*/
	while (h)
	{
		h = h->next;
		lenght++;
	}
	if (lenght == 1)
		return (1);

	/*put into array and reversed array*/
	while (tab)
	{
		tab_head[index] = tab->n;
		tab_reversed_head[lenght - index - 1] = tab->n;
		index++;
		tab = tab->next;
	}

	/*comparaison of the two arrays*/
	index = 0;
	while (index <= (lenght / 2))
	{
		if (tab_head[index] != tab_reversed_head[index])
			return (0);
		index++;
	}
	return (1);
}
