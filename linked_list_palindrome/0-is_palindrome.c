#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_middle - gets the middle node of a linked list
 * @head: pointer to head of list
 * Return: pointer to middle node
 */
listint_t *get_middle(listint_t *head)
{
    listint_t *slow = head;
    listint_t *fast = head;

    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/**
 * reverse_list - reverses a linked list
 * @head: pointer to head of list
 * Return: pointer to new head
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *middle, *second_half, *temp;
    int is_palindrome = 1;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return 1;

    /* Find middle of the list */
    middle = get_middle(*head);

    /* Reverse the second half */
    second_half = reverse_list(middle->next);

    /* Compare first half with reversed second half */
    temp = *head;
    while (second_half != NULL)
    {
        if (temp->n != second_half->n)
        {
            is_palindrome = 0;
            break;
        }
        temp = temp->next;
        second_half = second_half->next;
    }

    /* Restore the list by reversing the second half again */
    middle->next = reverse_list(middle->next);

    return is_palindrome;
}
