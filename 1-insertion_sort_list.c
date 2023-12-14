#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: Double pointer to the head of the doubly linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *swap_node;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		swap_node = current->prev;
		while (swap_node != NULL && swap_node->n > temp->n)
		{
			swap_node = swap_node->prev;
		}
		if (swap_node == NULL)
		{
			current = current->next;
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = *list;
			temp->prev = NULL;
			(*list)->prev = temp;
			*list = temp;
		}
		else if (swap_node->n > temp->n)
		{
			current = current->next;
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = swap_node;
			temp->prev = swap_node->prev;
			if (swap_node->prev != NULL)
				swap_node->prev->next = temp;
			swap_node->prev = temp;
		}
		else
			current = current->next;
		print_list((const listint_t *)*list);
	}
}