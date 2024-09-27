#include "monty.h"

/**
 * str_er -handles str errors
 *
 * @err_code: Error codes specific to string:
 *            10: int value inside a node is outside the valid ASCII range.
 *            11: Attempt to access a string but the stack is empty.
 *
 * Return: does not return as it terminates the program with an error
 */
void str_er(int err_code, ...)
{
	va_list args;
	int l_ber;

	va_start(args, err_code);
	l_ber = va_arg(args, int);
	switch (err_code)
	{
		case 10:
			fprintf(stderr, "Line%d: unable to pchar\n", l_ber);
			break;
		case 11:
			fprintf(stderr, "Line%d: unable to pchar since stack is empty\n",
					l_ber);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
