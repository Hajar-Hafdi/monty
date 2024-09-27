#include "monty.h"

/**
 * multp_nodes - multiplies two elmnts
 *
 * @stack: pointer
 * @l_ber: line num
 *
 * Return: void
 */
void multp_nodes(stack_t **stack, unsigned int l_ber)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mre_errors(8, l_ber, "mul");
	(*stack) = (*stack)->next;
	tot = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
