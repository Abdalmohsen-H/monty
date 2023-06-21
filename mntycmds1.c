#include "monty.h"

void pint(stack_t **stck , unsigned int ln_numbr)
{stack_t *popnod = get_dnodeint_at_index(globlData.head, 0);
	(void) stck;
	/*printf("pint on line: %u\n", ln_numbr);*/
	if (popnod == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln_numbr);
		/*free list first*/
		free_dlistint(globlData.head);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%u\n", popnod->n);
}

void pop(stack_t **stck , unsigned int ln_numbr)
{dlistint_t *current = NULL;
	(void) stck;
	(void) ln_numbr;	

	if  (globlData.head == NULL)
	{   
		fprintf(stderr, "L%u: can't pop an empty stack\n", ln_numbr);
		free_dlistint(globlData.head);
		exit(EXIT_FAILURE);    
	};  
	current = globlData.head;/*list have nodes and *head is the first node*/
	globlData.head = globlData.head->next;/*move *header to next node*/
	globlData.head->prev = NULL;
	free(current);
}

void swap(stack_t **stck , unsigned int ln_numbr)
{
	(void) stck;
	(void) ln_numbr;
	/* code for swap mnty opcode */
}

void add(stack_t **stck, unsigned int ln_numbr)
{
	(void) stck;
	(void) ln_numbr;
	/* code for add mnty opcode */
}

void nop(stack_t **stck, unsigned int ln_numbr)
{
	(void) stck;
	(void) ln_numbr;
	/* code for nop mnty opcode */
}
