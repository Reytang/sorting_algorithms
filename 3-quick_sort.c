#include "sort.h"
/**
 * partition - function of the prototype
 * @array: array to take in
 * @start: start of array
 * @end: end of array
 * @size: full size of array
 * Return: position of pivot
 */
int partition(int *array, int start, int end, int size)
{
	int pvot = array[end];
	int f = start, k, temp;

	for (k = start; k < end; k++)
	{
		if (array[k] <= pvot)
		{
			if (f != k)
			{
				temp = array[f];
				array[f] = array[k];
				array[k] = temp;
				print_array(array, size);
			}
			f++;
		}
	}
	if (f != end)
	{
		temp = array[f];
		array[f] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	printf("return f=%d\n", f);
	return (f);
}
/**
 * quickSort - function of the proyotype
 * @array: array to sort through
 * @start: start of array or subarray
 * @end: end of array or subarray
 * @size: size of full array
 */
void quickSort(int *array, int start, int end, int size)
{
	int pvot;

	if (start < end)
	{
		pvot = partition(array, start, end, size);
		printf("first recursive, start [%d] to pivot-1[%d]\n", start, pvot - 1);
		quickSort(array, start, pvot - 1, size);
		printf("second recursive, pivot+1 [%d] to end [%d]\n", pvot + 1, end);
		quickSort(array, pvot + 1, end, size);
	}
}
/**
 * quick_sort - function of the prototype
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}

