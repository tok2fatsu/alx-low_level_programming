#include "search_algos.h"

/**
 * advanced_search - Searches recursively for elements in the array.
 * @array: A pointer to the first element of the array.
 * @left: The starting index of the array.
 * @right: the ending index of the array.
 * @value: the value to search for.
 *
 * Return: If the value is not present or is NULL, -1.
 *	   Otherwise, the index where the value is located.
 *
 * Description: Prints the [sub]array being searched.
 */
int advanced_search(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (advanced_search(array, left, i, value));
	return (advanced_search(array, i + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array.
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *	   Otherwise, the first index where the value is located.
 *
 * Description: Prints the [sub]array bieng searched.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_search(array, 0, size - 1, value));
}
