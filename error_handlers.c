#include "monty.h"

/**
 * error_msg - outputs error messages
 *
 * @err_code: error codes: The error codes and their meanings are:
 *                         1: No input file provided or multiple files given.
 *                         2: File could not be opened or read successfully.
 *                         3: Invalid command (opcode) found in the input file.
 *                         4: Memory allocation failure (e.g., during malloc).
 *                         5: Incorrect parameter for "push" operation
 *                         6: Attempt to print from an empty stack "pint"
 *                         7: Attempt to pop from an empty stack.
 *                         8: Insufficient items in the stack for operation.
 *
 * Return: This function does not return a value, the program terminates
 *         if an error is encountered.
 */
void error_msg(int err_code, ...)
{
	va_list args;
	char *oper;
	int lber;

	va_start(args, err_code);

	switch (err_code)
	{
		case 1:
			fprintf(stderr, "Run: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Opening file %s failed\n",
					va_arg(args, char *));
			break;
		case 3:
			lber = va_arg(args, int);
			oper = va_arg(args, char *);
			fprintf(stderr, "L%d: unsupported operation %s\n", lber, oper);
			break;
		case 4:
			fprintf(stderr, "Error: malloc not succesful\n");
			break;
		case 5:
			fprintf(stderr, "L%d: RUN: push int\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * mre_errors - handles more errors
 *
 * @err_code: The error codes and their meanings are:
 *            6: Attempt to print from an empty stack ("pint" error).
 *            7: Attempt to pop from an empty stack.
 *            8: Insufficient items in the stack for operation.
 *            9: Divided by 0
 */
void mre_errors(int err_code, ...)
{
	va_list args;
	char *oper;
	int lber;

	va_start(args, err_code);

	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: unable to pint since stack is empty\n",
					va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "Line%d: unable to pop empty stack\n",
					va_arg(args, int));
			break;
		case 8:
			lber = va_arg(args, unsigned int);
			oper = va_arg(args, char *);
			fprintf(stderr, "L%d: unable %s, insuffi stack\n", lber, oper);
			break;
		case 9:
			fprintf(stderr, "Line%d: divided by 0\n",
					va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
