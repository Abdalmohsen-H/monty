#include "monty.h"
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
	int pshvalue;
	int idx = 0;
	char *psharg;
	(void) stck;
	(void) ln_numbr;
	/*printf("get new cmd\n");*/
	/*printf("globlData.crntcmdarg[1] = push int arg: %s\n", globlData.crntcmdarg[1]);*/
	/*printf("globlData.argsc: %d\n", globlData.argsc);*/

	if (globlData.crntcmdarg[1] == NULL)
	{
		perrpsh(ln_numbr);
	}
	psharg = globlData.crntcmdarg[1];
	/* Check if the argument is a valid integer */
	for (; psharg[idx] != '\0'; idx++)
	{
		if (psharg[0] == '-')
			continue;
		if ((psharg[idx] < '0' || psharg[idx] > '9') && psharg[idx] != ' ')
		{/*printf("(%c) not an integer ascii = (%d)\n", psharg[idx], psharg[idx]);*/
			perrpsh(ln_numbr);
		}
	}
	pshvalue = my_atoi(psharg);
	if (globlData.type == STACK)
		globlData.head = add_dnodeint(&globlData.head, pshvalue);
	else if (globlData.type == QUEUE)
		globlData.tail = add_dnodeint_end(&globlData.head, pshvalue);
}

void pall(stack_t **stck, unsigned int ln_numbr)
{/*printf("pall on line: %u\n", ln_numbr);*/
	(void) stck;
	(void) ln_numbr;
	print_dlistint(globlData.head);
}

void read_file(const char *inpt_file_name)
{
	FILE *myfile = fopen(inpt_file_name, "r");
	char tmpbuffer[BUF_SIZE], *mntyln_tokn, *args[BUF_SIZE];
	unsigned int ln_numbr = 1, argc = 0, i = 0;
	stack_t *stck = NULL;

	if (myfile == NULL)
	{fprintf(stderr, "Error: Can't open file %s\n", inpt_file_name);
		exit(EXIT_FAILURE);
	}
	globlData.type = STACK;/*intialize global struct variable*/
	globlData.head = NULL;
	globlData.tail = NULL;
	globlData.zfile = myfile;
	for (ln_numbr = 1; fgets(tmpbuffer, BUF_SIZE, myfile) != NULL; ln_numbr++)
	{mntyln_tokn = strtok(tmpbuffer, " \t\n");
		argc = 0;
		for (i = 0; i < BUF_SIZE; i++)
		{
			args[i] = NULL;
		}
		while (mntyln_tokn != NULL)
		{
			args[argc++] = mntyln_tokn;
			mntyln_tokn= strtok(NULL, " \t\n");
		}

		if (args[0] != NULL && args[0][0] != '#')
		{globlData.crntcmd = args[0];
			globlData.crntcmdarg = args;
			globlData.argsc = argc;
			/*printf("globlData.crntcmd : %s\n", globlData.crntcmd);*/
			/*printf("globlData.crntcmdarg : %s\n", globlData.crntcmdarg[1]);*/
			excut_mntycmd(args[0], &stck, ln_numbr);
		}
	}
	free_dlistint(globlData.head);
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
