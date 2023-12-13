#include "sort.h"

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
			}
		}
		/*if no two elements were swapped by inner loop*/
		/*then break*/
		if (swapped == false)
			break;
	}
}