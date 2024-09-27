#include "monty.h"

/**
 * fetch_function - fetches and find func for the opode
 *
 * @opode: opcode
 * @val: arg of opode
 * @fomat: storage format
 * @l_ber: line num
 * if 1 input as a queue
 *
 * Return: void
 */
void fetch_function(char *opde, char *val, int l_ber, int fomat)
{
	int u;
	int flg;

	instruction_t func_list[] = {
		{"push", apn_stack},
		{"pall", output_stack},
		{"pint", output_top},
		{"pop", del_top},
		{"nop", nop},
		{"swap", switch_nodes},
		{"add", apn_nodes},
		{"sub", subst_nodes},
		{"div", divsn_nodes},
		{"mul", multp_nodes},
		{"mod", modf_nodes},
		{"pchar", output_char},
		{"pstr", output_str},
		{"rotl", rotlft},
		{"rotr", rotrgt},
		{NULL, NULL}
	};
	if (opde[0] == '#')
		return;
	for (flg = 1, u = 0; func_list[u].opcode != NULL; u++)
	{
		 if (strcmp(opde, func_list[u].opcode) == 0)
		 {
			 exec_func(func_list[u].f, opde, val, l_ber, fomat);
			 flg = 0;
		 }
	}
	if (flg == 1)
		error_msg(3, l_ber, opde);
}
/**
 * exec_func - executes function
 *
 * @fun: ptr to function to be executed
 * @opode: opcode
 * @vale: numeric value
 * @l_ber: line num
 * @fomat: format specifier
 * 1 if entered as queue
 */
void exec_func(operation_func fun, char *opode, char *vale, int l_ber, int fomat)
{
	stack_t *nd;
	int flg;
	int u;

	flg = 1;
	if (strcmp(opode, "push") == 0)
	{
		if (vale != NULL && vale[0] == '-')
		{
			vale = vale + 1;
			flg = -1;
		}
		if (vale == NULL)
			error_msg(5, l_ber);
		for (u = 0; vale[u] != '\0'; u++)
		{
			if (isdigit(vale[u]) == 0)
				error_msg(5, l_ber);
		}
		nd = make_node(atoi(vale) * flg);
		if (fomat == 0)
			fun(&nd, l_ber);
		if (fomat == 1)
			append_que(&nd, l_ber);
	}
	else
	{
		fun(&head, l_ber);
	}
}
