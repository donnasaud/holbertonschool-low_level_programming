#include "lists.h"

/**
 * sum_dlistint - Sums all the data (n) in a dlistint_t list
 * @head: Pointer to the head of the list
 *
 * Return: The sum of all data (n), or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

