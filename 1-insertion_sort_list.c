#include "sort.h"

/**
 * insertion_sort_list - it sorts a doubly linked list of integers in
 * ascending order usingthe Insertion sort algorithm
 * @list: a list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *after, *before;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr != NULL)
	{
		after = curr->next;
		before = curr->prev;

		while (before != NULL && curr->n < before->n)
		{
			before->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = before;

			curr->prev = before->prev;
			curr->next = before;

			if (before->prev != NULL)
				before->prev->next = curr;
			else
				*list = curr;

			before->prev = curr;
			before = curr->prev;
			print_list(*list);
		}

		curr = after;
	}
}