#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - fuction of the prototype
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maximum, f;

	for (maximum = array[0], f = 1; f < size; f++)
	{
		if (array[f] > maximum)
			maximum = array[f];
	}

	return (maximum);
}

/**
 * radix_counting_sort - function of the prototype
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t f;

	for (f = 0; f < size; f++)
		count[(array[f] / sig) % 10] += 1;

	for (f = 0; f < 10; f++)
		count[f] += count[f - 1];

	for (f = size - 1; (int)f >= 0; f--)
	{
		buff[count[(array[f] / sig) % 10] - 1] = array[f];
		count[(array[f] / sig) % 10] -= 1;
	}

	for (f = 0; f < size; f++)
		array[f] = buff[f];
}

/**
 * radix_sort - fuction of the prototype
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int maximum, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	maximum = get_max(array, size);
	for (sig = 1; maximum / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
