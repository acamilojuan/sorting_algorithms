#include "sort.h"
/**
 * 
 * 
 * 
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j; 
	int tmp, index, minor = 0;

	if(size >= 2)
	{
		for(i = 0; i < size; i++)
		{
			minor = array[i];
			for(j = i + 1; j < size; j++)
			{
				if(array[j] < minor)
				{
					minor = array[j];
					index = j;
				}
			}
			if(minor != array[i])
			{
				tmp = array[i];
				array[i] = minor;
				array[index] = tmp;
				print_array(array, size);
			}

		}
	}
}
