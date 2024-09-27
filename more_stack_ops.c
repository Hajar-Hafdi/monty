#include "monty.h"

/**
 * output_top - outputs thetop node
 *
 * @stack: ptr
 * @l_ber: line num
 *
 * Return: void
 */
void output_top(stack_t **stack, unsigned int l_ber)
{
	if (stack == NULL || *stack == NULL)
		mre_errors(6, l_ber);
	printf("%d\n", (*stack)->n);
}

/**
 * nop - makes  nothing
 * @stack: ptr
 * @l_ber: line num
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int l_ber)
{
	(void)stack;
	(void)l_ber;
}
/**
 * switch_nodes - switches the top 2 articles
 *
 * @stack: ptr
 * @l_ber: line num
 *
 * Return: void
 */
void switch_nodes(stack_t **stack, unsigned int l_ber)
{
	stack_t *tp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mre_errors(8, l_ber, "switch");
	tp = (*stack)->next;
	(*stack)->next = tp->next;
	if (tp->next != NULL)
		tp->next->prev = *stack;
	tp->next = *stack;
	(*stack)->prev = tp;
	tp->prev = NULL;
	*stack = tp;
}
/**
 * apn_nodes - appends the top 2 articles of the stck
 *
 * @stack: ptr
 * @l_ber: line number
 *
 * Return: void
 */
void apn_nodes(stack_t **stack, unsigned int l_ber)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mre_errors(8, l_ber, "add");

	(*stack) = (*stack)->next;
	tot = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

