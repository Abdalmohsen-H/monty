#include "main.h"

void excut_mntycmd(char *opcode, stack_t **stck, unsigned int ln_numbr)
{int i = 0;
	instruction_t mntysyntax[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (; mntysyntax[i].opcode != NULL; i++)
	{
		if (strcmp(mntysyntax[i].opcode, opcode) == 0)
		{
			mntysyntax[i].f(stck, ln_numbr);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", ln_numbr, opcode);
	exit(EXIT_FAILURE);
}

void push(stack_t **stck, unsigned int ln_numbr)
{/*printf("push on line: %u\n", ln_numbr);*/
	int pshvalue, idx;
	int isdigit = 1;
	char *psharg;

	printf("get new cmd");
	if (globlData.crntcmdarg == NULL)
	{
		perrpsh(ln_numbr);
	}
	psharg = globlData.crntcmdarg;
	/* Check if the argument is a valid integer */
	for (; psharg[idx] != '\0'; idx++)
	{
		if (psharg[0] == '-')
			continue;
		if ((psharg[idx] < '0' || psharg[idx] > '9') && psharg[idx] != ' ')
		{isdigit = 0;
			printf("(%c) not an integer ascii = (%d)\n", psharg[idx], psharg[idx]);
			perrpsh(ln_numbr);
		}
	}
	if (isdigit)
	{pshvalue = my_atoi(psharg);
		if (globlData.type == STACK)
			globlData.head = add_dnodeint(&globlData.head, pshvalue);
		if (globlData.type == QUEUE)
			globlData.tail = add_dnodeint_end(&globlData.head, pshvalue);
	}
}

void perrpsh(unsigned int ln_numbr)
{
	fprintf(stderr, "L%u: usage: push integer\n", ln_numbr);
	/*free list first*/
	free_dlistint(globlData.head);
	exit(EXIT_FAILURE);	
}
void pall(stack_t **stck, unsigned int ln_numbr)
{/*printf("pall on line: %u\n", ln_numbr);*/
	print_dlistint(globlData.head);
}

void read_file(const char *inpt_file_name)
{
	FILE *myfile = fopen(inpt_file_name, "r");
	char tmpbuffer[BUF_SIZE], *mntycmd;
	unsigned int ln_numbr = 1;
	stack_t *stck = NULL;

	if (myfile == NULL)
	{fprintf(stderr, "Error: Can't open file %s\n", inpt_file_name);
		exit(EXIT_FAILURE);
	}
	globlData.type = STACK;/*intialize global struct variable*/
	globlData.head = NULL;
	globlData.tail = NULL;
	for (ln_numbr = 1; fgets(tmpbuffer, BUF_SIZE, myfile) != NULL; ln_numbr++)
	{globlData.fileline = tmpbuffer;
		mntycmd = strtok(tmpbuffer, " \t\n");
		if (mntycmd != NULL && mntycmd[0] != '#')
		{globlData.crntcmd = mntycmd;
			globlData.crntcmdarg = strtok(NULL, " \t\n");
			printf("globlData.fileline : %s\n", globlData.fileline);
			printf("globlData.crntcmd : %s\n", globlData.crntcmd);
			printf("globlData.crntcmdarg : %s\n", globlData.crntcmdarg);
			excut_mntycmd(mntycmd, &stck, ln_numbr);
		}
	}
	/*free_dlistint(globlData.head);*/
	fclose(myfile);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	read_file(argv[1]);

	return (EXIT_SUCCESS);
}
