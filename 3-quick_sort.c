#include "sort.h"
/**
 * split - Splits the array, puting the pivot in the right place
 * @array: Array of unsorted integers
 * @size: size of the array to sort
 * @low: initial index of the array
 * @high: Last index of the array
 * Return: index of the pivot
 */
int split(int *array, size_t size, int low, int high)
{
	int minor_count = low - 1;
	int count = low;
	int pivot = array[high], tmp;

	for (; count < high; count++)
	{
		if (array[count] <= pivot)
		{
			minor_count++;
			tmp = array[minor_count];
			array[minor_count] = array[count];
			array[count] = tmp;
			if (minor_count != count && array[count] != array[minor_count])
				print_array(array, size);

		}
	}
	minor_count++;
	tmp = array[minor_count];
	array[minor_count] = array[high];
	array[high] = tmp;
	if (minor_count != count)
		print_array(array, size);
	return (minor_count);
}
/**
 * recursive_sort - Sort recursively an print
 * @array: Array of unsorted integers
 * @size: size of the array to sort
 * @low: initial index of the array
 * @high: Last index of the array
*/
void recursive_sort(int *array, size_t size, int low, int high)
{
	int piv_idx;

	if (low < high)
	{
		piv_idx = split(array, size, low, high);
		recursive_sort(array, size, low, piv_idx - 1); /**quick_s array izquierda */
		recursive_sort(array, size, piv_idx + 1, high);  /**quick_s array derecha*/
	}
}
/**
 * quick_sort - Sorts an array of integers
* @array: Array of unsorted integers
 * @size: size of the array to sort
 */
void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	if (array != NULL && size >= 2) /**Caso de recursion */
	{
		recursive_sort(array, size, low, high);  /**quick_s array derecha*/
	}
}
