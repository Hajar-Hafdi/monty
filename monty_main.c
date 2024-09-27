#include "monty.h"
void open_file(const char *filename);
stack_t *head = NULL;


/**
 * main - program start
 *
 * @arc: args count
 * @arv: list of args
 *
 * Return: Always 0 (Success)
 */
int main(int arc, char *arv[])
{
	if (arc != 2)
	{
		fprintf(stderr, "RUN: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(arv[1]);
	free_nodes();
	return (0);
}
/**
 * make_node - makes a node
 *
 * @num: number to be in th nd
 *
 * Return: if successful a ptr to the nd, NULL if not
 */
stack_t *make_node(int num)
{
	stack_t *ndd;

	ndd = malloc(sizeof(stack_t));
	if (ndd == NULL)
		error_msg(4);
	ndd->next = NULL;
	ndd->prev = NULL;
	ndd->n = num;
	return (ndd);
}
/**
 * free_nodes - Frees node
 */
void free_nodes(void)
{
	stack_t *trp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		trp = head;
		head = head->next;
		free(trp);
	}
}
/**
 * append_que - appends nod to queue
 *
 * @nwnode: pointer
 * @l_ber: line number
 */
void append_que(stack_t **nwnode, __attribute__((unused))unsigned int l_ber)
{
	stack_t *tm;

	if (nwnode == NULL || *nwnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nwnode;
		return;
	}
	tm = head;
	while (tm->next != NULL)
		tm = tm->next;
	tm->next = *nwnode;
	(*nwnode)->prev = tm;
}
