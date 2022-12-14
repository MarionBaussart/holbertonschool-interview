#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *tmp, *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	if (*head == NULL)
    {
        new->next = NULL;
        *head = new;
    }
	else
	{
		while (current->next && current->next->n < number)
			current = current->next;
		if (current->next == NULL)
        {
            current->next = new;
            new->next = NULL;
        }
        else
        {
            tmp = current->next;
            current->next = new;
            new->next = tmp;
        }
	}

	return (new);
}
