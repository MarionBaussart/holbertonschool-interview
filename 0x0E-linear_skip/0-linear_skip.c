#include "search.h"
#include <stdio.h>
#include <math.h>


/**
 * linear_skip - function that searches for a value in a sorted list
 * of integers using the Jump search algorithm
 * jump step : square root of the size of the array
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: index where value is located,
 * -1 if value is not present in array or if array is NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp = list, *len = list;
	size_t j, last, jump_step, index = 0, lenght = 0;

	if (list == NULL)
		return (NULL);

	/* length of the list */
	while (len)
	{
		lenght++;
		len = len->next;
	}
	jump_step = sqrt(lenght);

	while (index < lenght && tmp->n < value)
	{
		index += jump_step;
		if (tmp->express)
		{
			tmp = tmp->express;
			printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
		}
	}

	if (index >= lenght)
		last = lenght - 1;
	else
		last = index;
	j = index - jump_step;
	printf("Value found between indexes [%ld] and [%ld]\n", j, last);
	while (j <= last && j < lenght)
	{
		while (list->index < j)
			list = list->next;
		printf("Value checked at index [%ld] = [%d]\n", j, list->n);
		if (list->n == value)
			return (list);
		j++;
	}
	return (NULL);
}
