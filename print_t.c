#include "monty.h"

/**
 * output_top - outputs top node
 *
 * @stack: pointer
 * @l_ber: Int
 */
void output_top(stack_t **stack, unsigned int l_ber)
{
	if (stack == NULL || *stack == NULL)
		mre_errors(6, l_ber);
	printf("%d\n", (*stack)->n);
}
