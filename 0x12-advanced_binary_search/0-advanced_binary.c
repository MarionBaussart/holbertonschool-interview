#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @begin: First element of the array
 * @end: Last element of the array
 */
void print_array(int *array, int begin, int end)
{
	int i = begin;

	printf("Searching in array: ");
	while (i <= end)
	{
		if (i > begin)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located, -1 if value is not present in array
 * or if array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (search_binary(array, 0, size - 1, value));
}

/**
 * search_binary - Search for a value in a sorted array
 * @array: pointer to the first element of the array to search in
 * @begin: First element of the array
 * @end: Last element of the array
 * @value: value to search for
 * Return: index where value is located
 */
int search_binary(int *array, int begin, int end, int value)
{
	int middle;

	print_array(array, begin, end);

	middle = ((end - begin) / 2) + begin;

	if (array[middle] == value && array[middle - 1] != value)
		return (middle);

	if (begin == end)
		return (-1);

	if (array[middle] >= value)
		return (search_binary(array, begin, middle, value));

	if (array[middle] <= value)
		return (search_binary(array, middle + 1, end, value));

	return (-1);
}
