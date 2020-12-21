#include "monty.h"

int main(int ac, char* av[])
{
	FILE *carp = NULL;
	instruction_t instruct[] = {
		{ "push", f_push},
		{ "pall", f_pall},
		{ "pint", f_pint},
		{ "pop", f_pop},
		{ "swap", f_swap},
		{ "add", f_add},
		{ "nop", f_nop}
	};
	if (ac != 2)
		printf("Numero de argumentos invalidos");
	else
		if((carp = fopen(ejemplo, "r")) != NULL)
		{
			
		}
}
