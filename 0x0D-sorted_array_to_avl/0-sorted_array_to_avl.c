#include "binary_trees.h"
#include <stdio.h>

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL || size < 1)
		return (NULL);

	tree = build_avl(tree, array, 0, size - 1);
	return (tree);
}

/**
 * build_avl - function that build an AVL Tree from an array
 * @parent: pointer to the parent node
 * @array: array of values to store in the tree
 * @start: index where start the array
 * @end: index where end the array
 * Return: pointer to the AVL tree, or NULL on failure
 */
avl_t *build_avl(avl_t *parent, int *array, size_t start, size_t end)
{
	avl_t *node;
	size_t index;

	index = (start + end) / 2;

	node = binary_tree_node(parent, array[index]);
	if (node == NULL)
		return (NULL);

	if (index != start)
		node->left = build_avl(node, array, start, index - 1);

	if (index != end)
		node->right = build_avl(node, array, index + 1, end);

	return (node);
}

/**
 * binary_tree_node - creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Integer stored in the node
 * Return: new binary tree node, or NULL if it failed
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
