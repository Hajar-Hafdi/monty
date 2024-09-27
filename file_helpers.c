#include "monty.h"
#include <stdio.h>

/**
 * init_file - initializes a file
 *
 * @file_setup: the file path
 *
 * Return: void
 */
void init_file(char *file_setup)
{
	FILE *fd = fopen(file_setup, "r");

	if (file_setup == NULL || fd == NULL)
		error_msg(2, file_setup);

	process_file(fd);
	close_file(fd);
}
/**
 * process_file - processes a file
 *
 * @fd: ptr to file descrpt
 *
 * Return: void
 */
void process_file(FILE *fd)
{
	int l_ber, fomat = 0;
	char *buf = NULL;
	size_t ln = 0;

	while (getline(&buf, &ln, fd) != -1)
	{
		fomat = tok_line(buf, l_ber, fomat);
		l_ber++;
	}
	free(buf);
}
/**
 * tok_line - tokenizes each line
 *
 * @buf: line from th fl
 * @l_ber: line num
 * @fomat: if 0 node will be input as a stack
 * if 1 input as a queue
 *
 * Return: returns 0 if stack 1 if queue
 */
int tok_line(char *buf, int l_ber, int fomat)
{
	char *opde, *val;
	const char *limeter = "\n ";

	if (buf == NULL)
		error_msg(4);
	opde = strtok(buf, limeter);
	if (opde == NULL)
		return (fomat);
	val = strtok(NULL, limeter);

	if (strcmp(opde, "stack") == 0)
		return (0);
	if (strcmp(opde, "queue") == 0)
		return (1);
	fetch_function(opde, val, l_ber, fomat);
	return (fomat);
}
