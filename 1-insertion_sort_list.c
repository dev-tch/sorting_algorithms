#include "sort.h"
/**
*insertion_sort_list - sort doubly linked list via method insertion sort
*@list: double pointer  to head of linked list
*Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node, *insert_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		insert_node = current->prev;
		while (insert_node != NULL && insert_node->n > current->n)
		{
			/* Swap nodes*/
			prev_node = insert_node->prev;
			next_node = current->next;
			if (prev_node != NULL)
				prev_node->next = current;
			else
				*list = current;
		if (next_node != NULL)
			next_node->prev = insert_node;
		insert_node->next = next_node;
		insert_node->prev = current;
		current->next = insert_node;
		current->prev = prev_node;
		print_list(*list);
		insert_node = prev_node;
		}
		current = current->next;
	}
}






