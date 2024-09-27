#ifndef _MONTY_H_
#define _MONTY_H_


#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>


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

extern stack_t *head;
extern stack_t *stack_top;
typedef void (*operation_func)(stack_t **, unsigned int);


void open_file(const char *filename);
void close_file(FILE *file);
void init_file(char *file_setup);
void del_top(stack_t **stack, unsigned int l_ber);
void output_stack(stack_t **stack,  unsigned int l_ber);
void apn_stack(stack_t **n_node, __attribute__((unused))unsigned int l_ber);
void output_char(stack_t **stack, unsigned int l_ber);
void output_str(stack_t **stack, __attribute__((unused))unsigned int  l_ber);
void rotlft(stack_t **stack, __attribute__((unused))unsigned int l_ber);
void rotrgt(stack_t **stack, __attribute__((unused))unsigned int l_ber);
void del_top(stack_t **stack, unsigned int l_ber);
void output_stack(stack_t **stack,  unsigned int l_ber);
void multp_nodes(stack_t **stack, unsigned int l_ber);
void modf_nodes(stack_t **stack, unsigned int l_ber);
void apn_nodes(stack_t **stack, unsigned int l_ber);
void switch_nodes(stack_t **stack, unsigned int l_ber);
void nop(stack_t **stack, unsigned int l_ber);
void output_top(stack_t **stack, unsigned int l_ber);

void exec_func(operation_func fun, char *opode, char *vale, int l_ber, int fomat);
void close_file(FILE *file);
char *parse_line(char *buf, char *l_ber, char *fomat);

int main(int arc, char *arv[]);
stack_t *make_node(int num);
void free_nodes(void);
void append_que(stack_t **nwnode, __attribute__((unused))unsigned int l_ber);
void init_file(char *file_setup);
void process_file(FILE *fd);
int tok_line(char *buf, int l_ber, int fomat);
void divsn_nodes(stack_t **stack, unsigned int l_ber);
void subst_nodes(stack_t **stack, unsigned int l_ber);
void str_er(int err_code, ...);
void mre_errors(int err_code, ...);
void error_msg(int err_code, ...);
void subst_nodes(stack_t **stack, unsigned int l_ber);
void fetch_function(char *opde, char *val, int l_ber, int fomat);


#endif
