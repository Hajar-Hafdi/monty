#include "monty.h"

/**
 * subst_nodes - substracts the top two ele of the stack
 *
 * @stack: ptr
 * @l_ber: line num
 *
 * Return: void
 */
void subst_nodes(stack_t **stack, unsigned int l_ber)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	mre_errors(8, l_ber, "sub");

	(*stack) = (*stack)->next;
	tot = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * divsn_nodes - divides two elmn of the stack
 *
 * @stack: ptr
 * @l_ber: line num
 *
 * Return: void
 */
void divsn_nodes(stack_t **stack, unsigned int l_ber)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mre_errors(8, l_ber, "div");

	if ((*stack)->n == 0)
		mre_errors(9, l_ber);

	(*stack) = (*stack)->next;
	tot = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
