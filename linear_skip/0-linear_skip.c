#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: pointer to the head of the skip list
 * @value: value to search for
 * Return: pointer to the first node containing value, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *prev;
	/* Check if list is NULL */
	if (list == NULL)
		return (NULL);

	express = list;
	prev = list;
	/* Traverse the express lane */
	while (express->express && express->n < value)
	{
		prev = express;
		express = express->express;
		printf("Value checked at index [%lu] = [%d]\n",
			express->index, express->n);
	}
	/* Handle end of express lane case */
	if (express->express == NULL && express->n < value)
	{
		prev = express;
		while (express->next)
			express = express->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, express->index);
	/* Linear search in identified range */
	while (prev && prev->index <= express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		prev->index, prev->n);
		if (prev->n == value)
		return (prev);
		if (!prev->next || prev->index == express->index)
		break;
		prev = prev->next;
	}
	return (NULL);
}
