#include "main.h"
/**
 *print_dlistint - print data of nodes
 * in doubly linked list
 *@h: head of D lnkdlist
 *or just node of list you have to check
 *
 *Return: num of nodes found
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *headtmp = h;
	size_t cntr = 0;

	if (headtmp == NULL)
		return (cntr);/*return 0*/
	while (headtmp->prev != NULL)
	{headtmp = headtmp->prev;
	}
	while (headtmp->next)
	{
		printf("%d\n", headtmp->n);
		cntr++;
		headtmp = headtmp->next;
	}
	printf("%d\n", headtmp->n);
	cntr++;
	return (cntr);
}
/**
 *add_dnodeint_end - insert node at end
 * of doubly linked list
 * and return this node address(double pintr)
 *@head: double pointr for head  of D lnkdlist
 *or just node of list you have to check
 *@n: data for new node
 *Return: return added node address(double pintr)
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t **headtmp = head;
	dlistint_t *newnod;

	newnod = (dlistint_t *) malloc(sizeof(dlistint_t));
	if (newnod == NULL)
	{
		return (NULL);
	}
	while (*headtmp != NULL && (*headtmp)->next != NULL)
	{headtmp = &(*headtmp)->next;
	}
	newnod->next = NULL;
	newnod->n = n;
	newnod->prev = *headtmp;
	if (*headtmp == NULL)
	{newnod->prev = NULL;
		*head = newnod;
		return (newnod);
	}
	if (*headtmp != NULL) /* (*headtmp)->next already = NULL*/
	{
		(*headtmp)->next = newnod;
	}
	/* *head = newnod;*/
	return (newnod);
}
/**
 *add_dnodeint - insert node at beginning
 * of doubly linked list
 * and return this node address(double pintr)
 *@head: double pointr for head  of D lnkdlist
 *or just node of list you have to check
 *@n: data for new node
 *Return: return added node address(double pintr)
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t **headtmp = head;
	dlistint_t *newnod;

	newnod = (dlistint_t *) malloc(sizeof(dlistint_t));
	if (newnod == NULL)
	{
		return (NULL);
	}
	while (*headtmp != NULL && (*headtmp)->prev != NULL)
	{headtmp = &(*headtmp)->prev;
	}
	newnod->next = *headtmp;
	newnod->n = n;
	newnod->prev = NULL;
	if (*headtmp != NULL)
	{
		(*headtmp)->prev = newnod;
	}
	*head = newnod;
	return (newnod);
}
/**
 *free_dlistint - free data& memory of nodes
 * in doubly linked list
 *@head: head of D lnkdlist
 *
 */
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		head->prev = NULL;
		head = head->next;
		free(head->prev);
	}
	head->prev = NULL;
	free(head);
}
/**
 *get_dnodeint_at_index - get node by index
 * in doubly linked list
 *@head: head of D lnkdlist
 *@index: index
 *Return: node if found index else NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{unsigned int cntr = 0;
	if (head == NULL)
		return (NULL);
	while (head != NULL)/*loop till list node*/
	{
		if (index == cntr)
			return (head);
		head = head->next;
		cntr++;
	}
	return (NULL);/* head == NULL */
}
