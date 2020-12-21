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
void checkFunction(void)
{
	instruction_t func_code[] = 
	{
		{"push"},
		{"pall"},
		{"pint"},
		{"pop"},
		{"swap"},
		{"add"},
		{"nop"},
		{NULL}
	};
	int i = 0;
	while (func_code[i].opcode != NULL)
	{
		if (strcmp(func_code[i].opcode, token) == 0)
		{
			printf("Function FOund-----%s\n",token);
			break;
		}
		i++;
	}
}
int check_push(char *s)
{
        char *accept = "push";
        int i = 0;
        if (s == NULL)
                return 0;
        while(s[i] == accept[i])
                i++;
        if (i == 5 && s[i] == ' ')
                return 1;
        return 0;
}
