#include "monty.h"

/**
 * pint - prints the top of a stack
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void pint(stack_t **stck, unsigned int ln_numbr)
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

/**
 * pop - removes a node from the top of a stack
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void pop(stack_t **stck, unsigned int ln_numbr)
{
	dlistint_t *current = NULL;
	(void) stck;
	(void) ln_numbr;

	if  (globlData.head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", ln_numbr);
		fclose(globlData.zfile);
		free_dlistint(globlData.head);
		exit(EXIT_FAILURE);
	}
	current = globlData.head;/*list have nodes and *head is the first node*/
	globlData.head = globlData.head->next;/*move *header to next node*/
	globlData.head->prev = NULL;
	free(current);
}

/**
 * swap - swaps the top two nodes of a stack
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void swap(stack_t **stck, unsigned int ln_numbr)
{
	int temp_1, temp_2;
	(void) stck;
	(void) ln_numbr;
	/* code for swap mnty opcode */
		if  (dlistint_len(globlData.head) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", ln_numbr);
		fclose(globlData.zfile);
		free_dlistint(globlData.head);
		exit(EXIT_FAILURE);
	}
	else if (dlistint_len(globlData.head) == 2)
	{temp_1 = globlData.head->n;
	 globlData.head->n = globlData.head->next->n;
	globlData.head->next->n = temp_1;
	}
	else
	{
	temp_1 = globlData.head->n;/*sets temp_1 to the 1st node's n value*/
	delete_dnodeint_at_index(&(globlData.head), 0);/*deletes 1st node and*/
	/* sets the head to the 2nd node*/
	temp_2 = globlData.head->n;/*sets temp_2 to the 2nd node's n value*/
	delete_dnodeint_at_index(&(globlData.head), 0);/*deletes 2nd node & sets*/
	/* head to next node if exists*/
	globlData.head = add_dnodeint(&(globlData.head), temp_1);
	globlData.head = add_dnodeint(&(globlData.head), temp_2);
	}

}

/**
 * add - adds the values present in the top two nodes of a stack
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void add(stack_t **stck, unsigned int ln_numbr)
{
	int a, b;
	(void) stck;
	(void) ln_numbr;
	/* code for add mnty opcode */
	if  (dlistint_len(globlData.head) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", ln_numbr);
		fclose(globlData.zfile);
		free_dlistint(globlData.head);
		exit(EXIT_FAILURE);
	};
	/*sets a to the value of the top element*/
	a = get_dnodeint_at_index(globlData.head, 0)->n;
	/*sets b to the value of the second top element*/
	b = get_dnodeint_at_index(globlData.head, 1)->n;
	/*deletes the first top element*/
	delete_dnodeint_at_index(&(globlData.head), 0);
	/*replaces 2nd tp[ element value with sum of a & b*/
	globlData.head->n = a + b;
}

/**
 * nop - does nothing
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void nop(stack_t **stck, unsigned int ln_numbr)
{
	(void) stck;
	(void) ln_numbr;
	/* code for nop mnty opcode */
}
