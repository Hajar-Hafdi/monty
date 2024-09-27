#include "monty.h"

/**
 * apn_stack - appends a node to stck
 *
 * @n_node: ptr
 * @l_ber: line number
 */
void apn_stack(stack_t **n_node, __attribute__((unused))unsigned int l_ber)
{
	stack_t *tp;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_node;
		return;
	}
	tp = head;
	head = *n_node;
	head->next = tp;
	tp->prev = head;
}
/**
 * output_stack - adds nd
 *
 * @stack: ptr
 * @l_ber: line num
 */
void output_stack(stack_t **stack,  unsigned int l_ber)
{
	stack_t *tp;

	(void) l_ber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	for (tp = *stack; tp != NULL; tp = tp->next)
	{
		printf("%d\n", tp->n);
	}
}
/**
 * del_top - appends a nd to stck
 *
 * @stack: ptr
 * @l_ber: line num
 *
 * Return: void
 */
void del_top(stack_t **stack, unsigned int l_ber)
{
	stack_t *tp;

	if (stack == NULL || *stack == NULL)
		mre_errors(7, l_ber);
	tp = *stack;
	*stack = tp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tp);
}
