#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * search_max - serach the max in an array
 * Description: serach the max number in an array
 * @a: array
 * @size: size of tab
 * Return: max number
 */
int search_max(int *a, size_t size)
{
	int max = a[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return (max);
}


/**
 * counting_sort - counting sort algorithm
 * Description: sort an array using counting sort algo
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	size_t i, k = 0;
	int x, j,  max, n;
	int *res;

	if (array != NULL && size > 1)
	{
		max = search_max(array, size);
		res = malloc(sizeof(int) * max + 1);
		if (res != NULL)
		{
			for (n = 0; n <= max; n++)
			{
				res[n] = 0;
			}
			for (i = 0; i < size; i++)
			{
				x = array[i];
				res[x] += 1;
			}
			print_array(res, max);
			for (n = 0; n <= max; n++)
			{
				if (res[n] > 0)
				{
					for (j = 1; j <= res[n]; j++)
					{
						array[k] = n;
						k++;
					}
				}
			}
			free(res);
			print_array(array, size);
		}
	}
}
