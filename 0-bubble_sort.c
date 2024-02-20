#include "sort.h"

/**
 *swap_sort - swap two intergers in given array
 *@a: pointer to be swap sorted
 *@b: pointer integer to be swaped
 */

void swap_sort(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 *bubble_sort - sorts an array of given intergers
 *@array: pointer to array list sorted
 *@size: size of the array being sorted
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int is_swapped = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0 ; i < size - 1 ; i++)
	{
		is_swapped = 0;
		for (j = 0 ; j < size - i - 1 ; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_sort(&array[j], &array[j + 1]);
				print_array(array, size);
				is_swapped = 1;
			}
		}
		if (is_swapped == 0)
			break;
	}
}
