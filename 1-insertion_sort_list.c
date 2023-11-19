#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly-linked list
 * @h: A pointer to head of doubly-linked list
 * @n1: A pointer to the first node to swap
 * @n2: The second node to swap
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *in, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itr = (*list)->next; itr != NULL; itr = temp)
	{
		temp = itr->next;
		in = itr->prev;
		while (i != NULL && itr->n < in->n)
		{
			swap_nodes(list, &in, itr);
			print_list((const listint_t *)*list);
		}
	}
}

