#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * shell_sort - shell sort algorithm
 * Description: sort an array using shell sort algo
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, h;
	int x;

	if (array != NULL && size > 1)
	{
		h = 1;
		while (h < (size / 3))
			h = (3 * h) + 1;
		while (h >= 1)
		{
			for (i = h; i < size; i++)
			{
				x = array[i];
				j = i;
				while ((j >= h) && (j - h + 1) >= 1 && array[j - h] > x)
				{
					array[j] = array[j - h];
					j = j - h;
				}
				array[j] = x;
			}
			h = h / 3;
			print_array(array, size);
		}
	}
}
