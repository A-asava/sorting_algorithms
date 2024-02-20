#include "sort.h"

/**
 *swap_sort - swaps two elements of a given array
 *@a: pointer to element being swaped
 *@b: pointer to the element swapd
 */

void swap_sort(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *lomuto_partition - sort the array elements through assigning
 *last element of array to pivote
 *@array: pointer to array to be sorted
 *@size: size of the aray
 *@first: first index elemnt of array
 *@last: last index element of given array
 *Return: always (0) on success
 */

int lomuto_partition(int *array, size_t size, int first, int last)
{
	int i, j, pivotindex;

	if (array == NULL || size < 2)
		return (0);

	pivotindex = array[last];
	i = first - 1;

	for (j = first ; j <= last - 1 ; j++)
	{
		if (array[j] <= pivotindex)
		{
			i++;
			if (i != j)
			{
				swap_sort(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[last])
	{
		swap_sort(&array[i + 1], &array[last]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 *quick_recurse - recurses lomuto partition
 *@array: pointer to a given array
 *@size: size of the given array
 *@first: first index
 *@last: last index
 */

void quick_recurse(int *array, size_t size, int first, int last)
{
	int pivotindex;

	if (array == NULL || size < 2)
		return;

	if (first < last)
	{
		pivotindex = lomuto_partition(array, size, first, last);
		quick_recurse(array, size, first, pivotindex - 1);
		quick_recurse(array, size, pivotindex + 1, last);
	}
}

/**
 *quick_sort - sorts elements of given array through quick sort
 *@array: pointer to th array being sort
 *@size: size of  array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_recurse(array, size, 0, size - 1);
}
