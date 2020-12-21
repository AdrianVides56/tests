#include "header.h"
/**
 * get_op_func - function that selects the correct function to perform the
 *               operation asked by the user.
 *
 * @s: This is the input operator
 *
 * Return: This function returns a pointer to the function that corresponds to
 *         the operator given as a parameter. Example: get_op_func("+")
 *         should return a pointer to the function op_add"")
 *         If s does not match any of the 5 expected operators
 *         (+, -, *, /, %),return NULL)
 *
 */
void checkFunction(const char *token, unsigned int line_number, stack_t **stack)
{
	instruction_t func_code[] = 
	{
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add"},
		{"nop"},
		{NULL}
	};
	int i = 0;
	while (func_code[i].opcode != NULL && token != NULL)
	{
		if (strcmp(func_code[i].opcode, token) == 0)
		{
			func_code[i].f(stack, line_number);
			break;
		}
		i++;
	}
	/*Print Error
	EXIT FAILURE */
}
int check_push(char *s)
{
        char *accept = "push";
        int i = 0;
        if (s == NULL)
                return 0;
        while(s[i] == accept[i] && accept[i] != '\0')
                i++;
        if (i == 4)
                return 1;
        return 0;
}
