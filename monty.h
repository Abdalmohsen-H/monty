#ifndef custom_header_monty
#define custom_header_monty

/* -- import libs --*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*-macro-*/
#define BUF_SIZE 256

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * enum DataTyp - used for global variable
 * @STACK: ...
 * @QUEUE: ...
 *
 * Description: determines whether the data type passed is a stack or a queue
 */
enum DataTyp
{
	STACK,
	QUEUE
};

/**
 * struct globData - opcode and its function
 * @type: determines whether the data type is a stack or a queue
 * @head: pointer to front of the data type
 * @tail: pointer to rear of the data type
 * @crntcmd: current command read
 * @crntcmdarg: pointer to current command read
 * @argsc: ...
 * @zfile: file being read
 *
 * Description: variables to access global data
 */
struct globData
{
	enum DataTyp type;
	stack_t *head;
	stack_t *tail;
	char *crntcmd;
	char **crntcmdarg;
	int argsc;
	FILE *zfile;
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
/*xtra funcs*/
void perrpsh(unsigned int ln_numbr);
int my_atoi(char *strn);
char *nul_trm_arg(char *cmdargmnt);
/*dlist handling funcs*/
typedef stack_t dlistint_t;
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
int sum_dlistint(dlistint_t *head);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
/*recently added*/
size_t dlistint_len(const dlistint_t *dlsthead);
int delete_dnodeint_at_index(dlistint_t **dlsthead, unsigned int index);
#endif
