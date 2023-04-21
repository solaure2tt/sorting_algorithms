#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * partition - partionning the array
 * Description - partionning the array
 * @a: array
 * @beg: index beginning
 * @end: index end
 * @size: size of array
 * Return: size_t
 */
size_t partition(int *a, size_t beg, size_t end, size_t size)
{
	size_t x, i, j;
	int pivot;

	pivot = a[end];
	i = beg - 1;
	for (j = beg; j < end; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			x = a[i];
			a[i] = a[j];
			a[j] = x;
			if (i != j)
				print_array(a, size);
		}
	}
	x = a[i + 1];
	a[i + 1] = a[end];
	a[end] = x;
	if ((i + 1) != end)
		print_array(a, size);
	return (i + 1);

}


/**
 * quickS - quicksort extension
 * Description: quiksort recursion
 * @a: array
 * @beg: begining
 * @end: end
 * @size: size array
 * Return: nothing
 */
void quickS(int *a, size_t beg, size_t end, size_t size)
{
	size_t ipiv;

	if (beg < end)
	{
		ipiv = partition(a, beg, end, size);
		if (ipiv > 0)
			quickS(a, beg, ipiv - 1, size);
		quickS(a, ipiv + 1, end, size);
	}
}
/**
 * quick_sort - quicksort sort algorithm
 * Description: sort a double link list using quick sort algo
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		quickS(array, 0, size - 1, size);
}
