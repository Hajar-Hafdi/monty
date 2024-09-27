#include "monty.h"

/**
 * output_char - output the ascii val
 *
 * @stack: pointer
 * @l_ber: line number
 */
void output_char(stack_t **stack, unsigned int l_ber)
{
	int sc;

	if (stack == NULL || *stack == NULL)
		str_er(11, l_ber);
	sc = (*stack)->n;
	if (sc < 0 || sc > 127)
		str_er(10, l_ber);
	printf("%c\n", sc);
}
/**
 * output_str - outputs a string
 *
 * @stack: pointer
 * @l_ber: line number
 */
void output_str(stack_t **stack, __attribute__((unused))unsigned int  l_ber)
{
	int sci;
	stack_t *tp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tp = *stack;
	while (tp != NULL)
	{
		sci = tp->n;
		if (sci <= 0 || sci > 127)
			break;
		printf("%c", sci);
		tp = tp->next;
	}
	printf("\n");
}
/**
 * rotlft -rotates 1st node
 *
 * @stack: pointer
 * @l_ber: line num
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int l_ber)
{
	stack_t *tp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tp = *stack;
	while (tp->next != NULL)
		tp = tp->next;
	tp->next = *stack;
	(*stack)->prev = tp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * rotrgt - rotates last node to top
 *
 * @stack: pointer
 * @l_ber: line number
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int l_ber)
{
	stack_t *tp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tp = *stack;
	while (tp->next != NULL)
		tp = tp->next;
	tp->next = *stack;
	tp->prev->next = NULL;
	tp->prev = NULL;
	(*stack)->prev = tp;
	*stack = tp;
}
