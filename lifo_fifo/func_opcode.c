#include "header.h"


void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = (stack_t *) malloc(sizeof(stack_t));
	stack_t *last = NULL;
	last = *stack;

	if (new_node == NULL)
	{
		free_list(*stack);
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if ((isdigit(*second) != 0) || (*second =='-' && isdigit(second[1])))
		new_node->n = atoi(second);
	else
	{
		free(new_node);
		free_list(*stack);
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	}
	printf("New node: %d\n", new_node->n);
}

void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *aux = NULL;

	if (*head == NULL)
		return;

	aux = *head;
	while (aux->next != NULL)
		aux = aux->next;
	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->prev;
	}
	
}     
