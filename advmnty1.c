#include "monty.h"
/**
 * sub - sub values of top two nodes of a stack
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void sub(stack_t **stck, unsigned int ln_numbr)
{
	int a, b;
	(void) stck;
	(void) ln_numbr;
	/* code for mnty opcode */
	if  (dlistint_len(globlData.head) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", ln_numbr);
		fclose(globlData.zfile);
		free_dlistint(globlData.head);
		exit(EXIT_FAILURE);
	};
	/*sets a to the value of the top element*/
	a = globlData.head->n;
	/*sets b to the value of the second top element*/
	b = globlData.head->next->n;
	/*deletes the first top element*/
	delete_dnodeint_at_index(&(globlData.head), 0);
	/*replaces value of new head with op result*/
	globlData.head->n = b - a;
}
/**
 * mul - mul values of top two nodes of a stack
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void mul(stack_t **stck, unsigned int ln_numbr)
{
	int a, b;
	(void) stck;
	(void) ln_numbr;
	/* code for mnty opcode */
	if  (dlistint_len(globlData.head) < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", ln_numbr);
		fclose(globlData.zfile);
		free_dlistint(globlData.head);
		exit(EXIT_FAILURE);
	};
	/*sets a to the value of the top element*/
	a = globlData.head->n;
	/*sets b to the value of the second top element*/
	b = globlData.head->next->n;
	/*deletes the first top element*/
	delete_dnodeint_at_index(&(globlData.head), 0);
	/*replaces value of new head with op result*/
	globlData.head->n = a * b;
}
/**
 * divs - div values of top two nodes of a stack
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void divs(stack_t **stck, unsigned int ln_numbr)
{
	int a, b;
	(void) stck;
	(void) ln_numbr;
	/* code for mnty opcode */
	if  (dlistint_len(globlData.head) < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", ln_numbr);
		fclose(globlData.zfile);
		free_dlistint(globlData.head);
		exit(EXIT_FAILURE);
	};
	/*sets a to the value of the top element*/
	a = globlData.head->n;
	/*sets b to the value of the second top element*/
	b = globlData.head->next->n;
	/*deletes the first top element*/
	delete_dnodeint_at_index(&(globlData.head), 0);
	/*replaces value of new head with op result*/
	globlData.head->n = b / a;
}
/**
 * mod - mod values of top two nodes of a stack
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void mod(stack_t **stck, unsigned int ln_numbr)
{
	int a, b;
	(void) stck;
	(void) ln_numbr;
	/* code for mnty opcode */
	if  (dlistint_len(globlData.head) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", ln_numbr);
		fclose(globlData.zfile);
		free_dlistint(globlData.head);
		exit(EXIT_FAILURE);
	}
	if  ((globlData.head->n) == 0)/*value of head is zero*/
	{
		fprintf(stderr, "L%u: division by zero\n", ln_numbr);
		fclose(globlData.zfile);
		free_dlistint(globlData.head);
		exit(EXIT_FAILURE);
	}
	/*sets a to the value of the top element*/
	a = globlData.head->n;
	/*sets b to the value of the second top element*/
	b = globlData.head->next->n;
	/*deletes the first top element*/
	delete_dnodeint_at_index(&(globlData.head), 0);
	/*replaces value of new head with op result*/
	globlData.head->n = b % a;
}
/**
 * pchar - print value of head as ascii
 * @stck: ...
 * @ln_numbr: line number where the command is present
 *
 * Return: void
 */
void pchar(stack_t **stck, unsigned int ln_numbr)
{int val;
	(void) stck;
	(void) ln_numbr;
	/* code for mnty opcode */
	if  (globlData.head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", ln_numbr);
		fclose(globlData.zfile);
		exit(EXIT_FAILURE);
	}
	val = globlData.head->n;
	if (val < 32 || val > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", ln_numbr);
		fclose(globlData.zfile);
		free_dlistint(globlData.head);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", val);
}
