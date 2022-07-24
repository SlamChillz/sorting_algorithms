#include "sort.h"

/**
  * swap - switches nodes
  * @list: double linked list
  * @previous: left node
  * @next: right node
  *
  * Return: void
  */
void swap(listint_t **list, listint_t *previous, listint_t *next)
{
	listint_t *temp;

	temp = previous->prev;
	if (temp)
		temp->next = next;
	else
		*list = next;
	next->prev = temp;

	previous->prev = next;
	previous->next = next->next;
	next->next = previous;
	if (previous->next != NULL)
		previous->next->prev = previous;
	previous = temp;
}

/**
  * cocktail_sort_list - sorts a doubly linked list
  * ascendingly using the `Cocktail shaker sort` algorithm
  * @list: head node to a doubly linked list
  *
  * Return: void
  */
void cocktail_sort_list(listint_t **list)
{
	bool swapped;
	listint_t *next, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	swapped = true;

	while (swapped)
	{
		swapped = false;
		current = *list;
		for ( ; current->next; current = next)
		{
			next = current->next;
			if (current->n > next->n)
			{
				swap(list, current, next);
				print_list(*list);
				swapped = true;
			}
		}
		if (!swapped)
			break;
		swapped = false;

		for ( ; current->prev; current = current->prev)
		{
			next = current->prev;
			if (current->n < next->n)
			{
				swap(list, next, current);
				print_list(*list);
				current = current->next;
				swapped = true;
			}
		}
	}
}
