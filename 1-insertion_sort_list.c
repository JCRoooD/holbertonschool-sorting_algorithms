#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;
	/* If list is NULL, empty, or has only one element, do nothing */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	/* Loop through the list and compare each element to the previous */
	while (current != NULL)
	{
		tmp = current;
		/* If the element is less than the previous, swap them */
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;
			/* If the element is the new head, update the list */
			if (tmp->prev == NULL)
			{
				*list = tmp;
			}
			else /* Otherwise, update the previous element */
				tmp->prev->next = tmp;
			print_list(*list);
		}
		current = current->next;
	}
}
