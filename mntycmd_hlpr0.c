#include "monty.h"
/**
 * perrpsh - returns an error for push
 * @ln_numbr: line number where the error is present
 *
 * Return: void
 */
void perrpsh(unsigned int ln_numbr)
{
	fprintf(stderr, "L%u: usage: push integer\n", ln_numbr);
	fclose(globlData.zfile);
	/*free list first*/
	free_dlistint(globlData.head);
	exit(EXIT_FAILURE);
}
