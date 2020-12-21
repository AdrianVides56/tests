#include "header.h"
void free_list(stack_t *stack)
{
	stack_t *aux;

	while (stack != NULL)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
	stack = NULL;
}
