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
	globlData.type = STACK;/*intialize global struct variable*/
	globlData.head = NULL;
	globlData.tail = NULL;

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
{
	printf("push on line: %u\n", ln_numbr);
	/* code for push mnty opcode */
}

void pall(stack_t **stck, unsigned int ln_numbr)
{printf("pall on line: %u\n", ln_numbr);
	/* code for pall mnty opcode */
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

	for (ln_numbr = 1; fgets(tmpbuffer, BUF_SIZE, myfile) != NULL; ln_numbr++)
	{
		mntycmd = strtok(tmpbuffer, " \t\n");
		if (mntycmd != NULL && mntycmd[0] != '#')
		{
			excut_mntycmd(mntycmd, &stck, ln_numbr);
		}
	}
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
