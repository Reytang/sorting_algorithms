#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - function of theprototype
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * max_heapify - function of the prototype
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, larger;

	left = 2 * root + 1;
	right = 2 * root + 2;
	larger = root;

	if (left < base && array[left] > array[larger])
		larger = left;
	if (right < base && array[right] > array[larger])
		larger = right;

	if (larger != root)
	{
		swap_ints(array + root, array + larger);
		print_array(array, size);
		max_heapify(array, size, base, larger);
	}
}

/**
 * heap_sort - function of the prototype
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int f;

	if (array == NULL || size < 2)
		return;

	for (f = (size / 2) - 1; f >= 0; f--)
		max_heapify(array, size, size, f);

	for (f = size - 1; f > 0; f--)
	{
		swap_ints(array, array + f);
		print_array(array, size);
		max_heapify(array, size, f, 0);
	}
}
