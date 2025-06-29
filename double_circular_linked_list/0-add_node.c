#include <stdlib.h>
#include <string.h>
#include "list.h"

/* Function prototypes in case they're missing from list.h */
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: Pointer to the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
		List *new_node;
		List *last;

		if (!list || !str)
				return (NULL);

		/* Create new node */
		new_node = malloc(sizeof(List));
		if (!new_node)
				return (NULL);

		/* Copy string */
		new_node->str = malloc(strlen(str) + 1);
		if (!new_node->str)
		{
				free(new_node);
				return (NULL);
		}
		strcpy(new_node->str, str);

		/* If list is empty */
		if (!*list)
		{
				new_node->next = new_node;
				new_node->prev = new_node;
				*list = new_node;
				return (new_node);
		}

		/* Find the last node (the one before the head) */
		last = (*list)->prev;

		/* Insert new node at the end */
		new_node->next = *list;
		new_node->prev = last;
		last->next = new_node;
		(*list)->prev = new_node;

		return (new_node);
}

/**
 * add_node_begin - Add a new node to the beginning of a double circular linked list
 * @list: Pointer to the list to modify
 * @str: String to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
		List *new_node;
		List *last;

		if (!list || !str)
				return (NULL);

		/* Create new node */
		new_node = malloc(sizeof(List));
		if (!new_node)
				return (NULL);

		/* Copy string */
		new_node->str = malloc(strlen(str) + 1);
		if (!new_node->str)
		{
				free(new_node);
				return (NULL);
		}
		strcpy(new_node->str, str);

		/* If list is empty */
		if (!*list)
		{
				new_node->next = new_node;
				new_node->prev = new_node;
				*list = new_node;
				return (new_node);
		}

		/* Find the last node (the one before the current head) */
		last = (*list)->prev;

		/* Insert new node at the beginning */
		new_node->next = *list;
		new_node->prev = last;
		(*list)->prev = new_node;
		last->next = new_node;

		/* Update head pointer */
		*list = new_node;

		return (new_node);
}
