#include "slide_line.h"
#include <stdio.h>


/**
 * slide_number_left - slides all numbers to the left
 *
 * @line: points to an array of integers containing @size elements,
 * that must be slided & merged to the direction represented by @direction
 * @size: Number of elements in @line
 * @direction: SLIDE_LEFT
 *
 * Return: no return
 */
void slide_number_left(int *line, size_t size, int direction)
{
	size_t i, j;

	/*SLIDE_LEFT*/
	if (direction == 0)
	{
		i = 0, j = 1;
		while (i < size)
		{
			if (line[i] == 0)
			{
				while (j < size)
				{
					if (line[j] == 0)
						j++;
					else
						break;
				}
				if (j < size)
					line[i] = line[j];
				line[j] = 0;
			}
			i++;
			if (j < size)
				j++;
		}
	}
}


/**
 * slide_number_right - slides all numbers to the right
 *
 * @line: points to an array of integers containing @size elements,
 * that must be slided & merged to the direction represented by @direction
 * @size: Number of elements in @line
 * @direction: SLIDE_RIGHT
 *
 * Return: no return
 */
void slide_number_right(int *line, size_t size, int direction)
{
	size_t i, j;

	/*SLIDE_RIGHT*/
	if (direction == 1)
	{
		i = size - 1, j = size - 2;
		while (i + 1 > 0)
		{
			if (line[i] == 0)
			{
				while (j + 1 > 0)
				{
					if (line[j] == 0)
						j--;
					else
						break;
				}
				if (j + 1 > 0)
					line[i] = line[j];
				line[j] = 0;
			}
			i--;
			if (j + 1 > 0)
				j--;
		}
	}
}


/**
 * merge_number - merges an array of integers
 *
 * @line: points to an array of integers containing @size elements,
 * that must be slided & merged to the direction represented by @direction
 * @size: Number of elements in @line
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: no return
 */
void merge_number(int *line, size_t size, int direction)
{
	size_t i = 0;

	if (direction == 0)
	{
		while (i < size - 1)
		{
			if (line[i] == line[i + 1])
			{
				line[i] += line[i + 1];
				line[i + 1] = 0;
			}
			i++;
		}
		slide_number_left(line, size, direction);
	}

	if (direction == 1)
	{
		i = size - 1;
		while (i > 0)
		{
			if (line[i] == line[i - 1])
			{
				line[i] += line[i - 1];
				line[i - 1] = 0;
			}
			i--;
		}
		slide_number_right(line, size, direction);
	}
}


/**
 * slide_line - slides and merges an array of integers
 *
 * @line: points to an array of integers containing @size elements,
 * that must be slided & merged to the direction represented by @direction
 * @size: Number of elements in @line
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != 0 && direction != 1)
		return (0);
	if (direction == 0)
	{
		slide_number_left(line, size, direction);
		merge_number(line, size, direction);
	}

	if (direction == 1)
	{
		slide_number_right(line, size, direction);
		merge_number(line, size, direction);
	}
	return (1);
}
