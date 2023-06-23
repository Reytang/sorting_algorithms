#include "sort.h"
/**
 * prints - function of the prototype
 * @arr: original or tmp array
 * @side: left, right, or merged half
 * @start: starting index
 * @end: ending index
 */
void prints(int *arr, char *side, size_t start, size_t end)
{
	size_t x;

	printf("[%s]: ", side);
	for (x = start; x < end; x++)
	{
		if (x != (end - 1))
			printf("%d, ", arr[x]);
		else
			printf("%d\n", arr[x]);
	}

}
/**
 * rec_merge - function of the prototype
 * @array: original array
 * @sortArr: tmp array to hold sorted elements
 * @l: starting index
 * @r: ending index
 */
void rec_merge(int *array, int *sortArr, size_t l, size_t r)
{
	size_t x, l_half, r_half;
	size_t mid = (l + r) / 2;

	if (r - l <= 1)
		return;

	rec_merge(array, sortArr, l, mid);
	rec_merge(array, sortArr, mid, r);
	printf("Merging...\n");
	prints(array, "left", l, mid);
	prints(array, "right", mid, r);
	l_half = l;
	r_half = mid;
	for (x = l; x < r; x++)
	{
		if ((l_half < mid) &&
		    ((r_half == r) || (array[l_half] < array[r_half])))
		{
			sortArr[x] = array[l_half];
			l_half++;
		}
		else
		{
			sortArr[x] = array[r_half];
			r_half++;
		}
	}
	prints(sortArr, "Done", l, r);
	for (x = l; x < r; x++)
		array[x] = sortArr[x];
}
/**
 * merge_sort - sorts mergly
 * @array: array sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *sortArr;

	if (!(array) || size < 2)
		return;
	sortArr = malloc(sizeof(int) * size);
	if (!(sortArr))
		return;
	rec_merge(array, sortArr, 0, size);
	free(sortArr);
}

