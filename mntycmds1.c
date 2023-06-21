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
{
	(void) stck;
	(void) ln_numbr;	
	printf("pop on line: %u\n", ln_numbr);
	/* code for pop mnty opcode */
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
