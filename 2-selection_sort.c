#include "sort.h"

/**
 *swap_sort - The function swaps two integers in array
 *@a: pointer to integer to swap
 *@b: pointer to integer to swap
 */

void swap_sort(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *selection_sort - sorts the array by selecton
 *@array: pointer to the array list to be sorted
 *@size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, minimum_index;

	if (array == NULL || size < 2)
		return;
	for (i = 0 ; i < size - 1 ; i++)
	{
		minimum_index = i;
		for (j = i + 1 ; j < size ; j++)
		{
			if (array[j] < array[minimum_index])
				minimum_index = j;
		}
		if (minimum_index != i)
		{
			swap_sort(&array[minimum_index], &array[i]);
			print_array(array, size);
		}
	}
}
