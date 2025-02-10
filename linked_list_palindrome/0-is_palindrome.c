#include <stdlib.h>
#include <lists.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/**
 * Helper function to reverse a linked list
 * Returns pointer to new head
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
 * is_palindrome - checks if a linked list is a palindrome
 * @head: pointer to pointer to the head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
    /* Empty list or single node */
    if (*head == NULL || (*head)->next == NULL)
        return 1;
        
    /* Find middle using slow and fast pointers */
    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev_slow = *head;
    
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }
    
    /* If odd number of nodes, skip middle node */
    if (fast != NULL)
    {
        slow = slow->next;
    }
    
    /* Reverse second half */
    prev_slow->next = NULL;  /* Split the list */
    listint_t *second_half = reverse_list(slow);
    
    /* Compare first half with reversed second half */
    listint_t *first_half = *head;
    listint_t *second_half_head = second_half;  /* Save for restoration */
    int is_palin = 1;
    
    while (first_half != NULL && second_half != NULL)
    {
        if (first_half->n != second_half->n)
        {
            is_palin = 0;
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }
    
    /* Restore the list (optional) */
    second_half = reverse_list(second_half_head);
    prev_slow->next = second_half;
    
    return is_palin;
}