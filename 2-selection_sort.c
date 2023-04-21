#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * selection_sort - selection sort algorithm
 * Description: sort a double link list using selction sort algo
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, pmin;
	int x;

	if (array != NULL && size > 1)
	{
		i = 0;
		while (i < size - 1)
		{
			pmin = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[pmin])
				{
					pmin = j;
				}
			}
			if (i != pmin)
			{
				x = array[i];
				array[i] = array[pmin];
				array[pmin] = x;
				print_array(array, size);
			}
			i++;
		}
	}
}
