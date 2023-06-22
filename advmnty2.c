#include "monty.h"
/**
 * pstr - print ascii value of stack as chars
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void pstr(stack_t **stck, unsigned int ln_numbr)
{int val;
	(void) stck;
	(void) ln_numbr;
	/* code for mnty opcode */
	if  (globlData.head == NULL)
	{
		fprintf(stderr, "L%u: can't pstr, stack empty\n", ln_numbr);
		fclose(globlData.zfile);
		exit(EXIT_FAILURE);
	}
	while (globlData.head != NULL)
	{
		val = globlData.head->n;
		if (val < 32 || val > 126)
		{
			/*fprintf(stderr, "L%u: can't pstr, value out of range\n", ln_numbr);*/
			fclose(globlData.zfile);
			free_dlistint(globlData.head);
			exit(EXIT_FAILURE);
		}
		fprintf(stdout, "%c\n", val);
		globlData.head = globlData.head->next;
	}
}
/**
 * rotl - rotl values of a stack
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void rotl(stack_t **stck, unsigned int ln_numbr)
{int val;
	(void) stck;
	(void) ln_numbr;

	/* code for mnty opcode */
	if  (globlData.head != NULL)
	{val = globlData.head->n;
		delete_dnodeint_at_index(&(globlData.head), 0);
		add_dnodeint_end(&(globlData.head), val);
	}
}
/**
 * rotr - rotr values of a stack
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void rotr(stack_t **stck, unsigned int ln_numbr)
{int val;
	dlistint_t *headtmp = globlData.head;
	size_t cntr = 0;
	(void) stck;
	(void) ln_numbr;
	while (headtmp->prev != NULL)
	{headtmp = headtmp->prev;
	}


	/* code for mnty opcode */
	if  (globlData.head != NULL && globlData.head->next != NULL)
	{
		while (headtmp != NULL)
		{cntr++;
			headtmp = headtmp->next;
		}
		val = headtmp->n;
		delete_dnodeint_at_index(&(globlData.head), cntr);
		add_dnodeint(&(globlData.head), val);
			headtmp = NULL;
	}
}
