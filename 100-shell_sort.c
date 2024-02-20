#include "sort.h"

/**
 *swap_sort - swaps two integers in given array
 *@a: pointer to the integer to be swaped
 *@b: pointer to the integer to swaped
 */

void swap_sort(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *shell_sort - sorts a given array of integers utilising
 *shell sort algorithm
 *@array: pointer to array to  be sorted
 *@size: size of array to be sorted
 */

void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;

	if (array == NULL || size < 2)
		return;
	interval = 1;
	while (interval < size / 3)
	{
		interval = interval * 3 + 1;
	}
	while (interval >= 1)
	{
		for (i = interval ; i < size ; i++)
		{
			for (j = i ; j >= interval ; j -= interval)
			{
				if (array[j] < array[j - interval])
				{
					swap_sort(&array[j], &array[j - interval]);
				}
				else
					break;
			}
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
