#include "monty.h"

/**
 * push - adds node to beginning of list
 * @head: address of previous "first" element
 * @n: integer value to be copied into node
 * Return: address to new node
 */
stack_t *push(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->next = *head;
	new->prev = NULL;
	new->n = n;
	*head = new;

	return (new);
}
/**
 * go_to_end - traverses to end of linked list
 * @head: ptr to head
 * Return: end node
 */
stack_t go_to_end(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
/**
 * enqueue - adds node to end of list
 * @head: address of first element
 * @n: int to put into new node
 * Return: address to new node
 */
stack_t *enqueue(stack_t **head, const int n)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	temp = *head;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (temp->next);
}
/**
 * pop - deletes node at head and advances to next node
 * @head: double ptr to head
 * Return: 1 on success, -1 on failure
 */
int pop(stack_t **head)
{
	stack_t *temp;
	unsigned int i;

	if (!(head) || !(*head))
		return (-1);
	temp = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(temp);
		return (1);
	}
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
	return (1);
}
/**
 * dequeue - removes node from end of linked list
 * @head: double ptr to head
 * Return: 1 on success, -1 on failure
 */
int dequeue(stack_t **head)
{
	if (!(head) || !(*head))
		return (-1);
	temp = *head;
	if ((*head)->next == NULL)
	{
		*head = NULL;
		free(temp);
		return (1);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->next = NULL;
	free(temp);
	return (1);

}
