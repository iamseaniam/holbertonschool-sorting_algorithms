#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}

/**
 * lomuto_sort - implements the quicksort algorithm through recursion
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: nothing
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		lomuto_sort(array, low, pivot - 1, size);
		lomuto_sort(array, pivot + 1, high, size);
	}
}
/**
 * lomuto_partition - orders a subset of an array of integers
 * according to the Lomuto partition scheme
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: final partition index
 */
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
		}
		}
	}
	if (pivot < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - swaps two integers in an array
 * @a: first integer to be swapped
 * @b: second integer to be swapped
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
