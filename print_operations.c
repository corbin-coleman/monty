#include "monty.h"
/**
 * pall - prints n values of all nodes
 * @head: ptr to head
 * Return: none
 */
void pall(stack_t **head)
{
	if (!(head) || !(*head))
		return;
	temp = *head;
	while (temp != NULL)
	{
		printf("%s\n",temp->n);
		temp = temp->next;
	}
}
/**
 * pint - prints n value of head
 * @head: ptr to head
 * Return: none
 */
void pint(stack_t **head)
{
	if (!(head) || !(*head))
		return;
	printf("%s\n", head->n);
}
/* this file will eventually include pchar and pstr*/
