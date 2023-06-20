#ifndef custom_header_monty
#define custom_header_monty

/* -- import libs --*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-macro-*/
#define BUF_SIZE 256
/*-struct given-*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*-used for global variable-*/
enum DataTyp
{
	STACK,
	QUEUE
};

struct globData
{
	enum DataTyp type;
	struct stack_si *head;
	struct stack_s *tail;
};

/*--global variable--*/

struct globData globlData;

/*-funcs-*/
void push(stack_t **stck, unsigned int ln_numbr);
void pall(stack_t **stck, unsigned int ln_numbr);
void pint(stack_t **stck, unsigned int ln_numbr);
void pop(stack_t **stck, unsigned int ln_numbr);
void swap(stack_t **stck, unsigned int ln_numbr);
void add(stack_t **stck, unsigned int ln_numbr);
void nop(stack_t **stck, unsigned int ln_numbr);

#endif
