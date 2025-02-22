#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow, *fast;

    /* If list is empty or has only one node, there can't be a cycle */
    if (list == NULL || list->next == NULL)
        return (0);

    slow = list;
    fast = list->next;

    while (fast != NULL && fast->next != NULL)
    {
        /* If fast and slow meet, there is a cycle */
        if (fast == slow)
            return (1);
            
        /* Move slow one step and fast two steps */
        slow = slow->next;
        fast = fast->next->next;
    }

    /* If we reach here, we found NULL, so no cycle */
    return (0);
}