#include "monty.h"
void perrpsh(unsigned int ln_numbr)
{
	fprintf(stderr, "L%u: usage: push integer\n", ln_numbr);
        fclose(globlData.zfile);   
	/*free list first*/
	free_dlistint(globlData.head);
	exit(EXIT_FAILURE);	
}
