#include "monty.h"

/**
 * modf_nodes - mods two elmnts from the stack
 *
 * @stack: ptr
 * @l_ber: line num
 *
 * Return: void
 */
void modf_nodes(stack_t **stack, unsigned int l_ber)
{
	int tot;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mre_errors(8, l_ber, "mod");
	if ((*stack)->n == 0)
		mre_errors(9, l_ber);
	(*stack) = (*stack)->next;
	tot = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = tot;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
