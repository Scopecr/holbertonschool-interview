#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - Helper function to create a new node with a copy of str
 * @str: The string to copy
 *
 * Return: Pointer to the new node or NULL on failure
 */
static List *create_node(char *str)
{
	List *new_node = malloc(sizeof(List));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/**
 * add_node_begin - Adds a new node to the beginning of a circular doubly list
 * @list: Address of pointer to the head node
 * @str: String to store in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	new_node = create_node(str);
	if (new_node == NULL)
	{
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		List *last = (*list)->prev;

		new_node->next = *list;
		new_node->prev = last;
		last->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;
	}

	return (new_node);
}

/**
 * add_node_end - Adds a new node to the end of a circular doubly list
 * @list: Address of pointer to the head node
 * @str: String to store in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node;

	new_node = create_node(str);
	if (new_node == NULL)
	{
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		List *last = (*list)->prev;

		new_node->next = *list;
		new_node->prev = last;
		last->next = new_node;
		(*list)->prev = new_node;
	}

	return (new_node);
}
