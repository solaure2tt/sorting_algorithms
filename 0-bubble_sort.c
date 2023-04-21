#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * bubble_sort - bubble sort algorithm
 * Description: sort a double link list using bubble sort algo
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int x;
	int sort;

	if (array != NULL && size > 1)
	{
		for (i = 0; i < size ; i++)
		{
			sort = 1;
			for (j = 0; j < size - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					x = array[j + 1];
					array[j + 1] = array[j];
					array[j] = x;
					print_array(array, size);
					sort = 0;
				}
			}
			if (sort == 1)
				break;
		}
	}
}
