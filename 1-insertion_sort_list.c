#include "sort.h"

/**
  * insertion_sort_list - sorts list in ascending order using insert sort
  * @list: head node of double linked list to be sorted
  *
  * Return: void
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current, *previous, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	head = *list, current = (*list)->next;

	for ( ; current; current = next)
	{
		previous = current->prev;
		next = current->next;
		while (previous && current->n < previous->n)
		{
			previous->next = current->next;
			if (current->next)
				current->next->prev = previous;
			current->next = previous;
			current->prev = previous->prev;
			if (previous->prev)
				previous->prev->next = current;
			else
				head = current;
			previous->prev = current;
			previous = current->prev;
			print_list(head);
		}
	}
	*list = head;
}
