#include "sort.h"
/**
 * swap - Function to swap nodes
 * @list: Double linked list
 * @back: Pointer to the struct to reference the back node
 * @front: Pointer to the struct to reference the front node
 */
void swap(listint_t **list, listint_t *back, listint_t *front)
{
	if (back->prev)
		back->prev->next = front;
	else
		*list = front;
	back->next = front->next;
	front->next = back;
	if (back->next)
		back->next->prev = back;
	front->prev = back->prev;
	back->prev = front;
}
/**
 * insertion_sort_list - Function to implement the Insertion Sort Algorithm
 * @list: Double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *back, *front;

	back = (*list);
	front = (*list)->next;
	current = front->next;

	if ((*list)->next)
	{
		while (front)
		{
			while (front->prev && front->prev->n > front->n)
			{
				swap(list, back, front);
				/**front = current->prev;*/
				back = front->prev;
				print_list(*list);
			}
			front = current;
			if (front)
			{
				current = current->next;
				back = front->prev;

			}
			else
			{
				break;
			}
		}
	}