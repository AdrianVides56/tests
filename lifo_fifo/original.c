#include "header.h"
#define DELIM " \t\n"

char *second;

int main(int ac, char *av[])
{
	FILE *ifp;
	stack_t *stack = NULL;
	ssize_t read = 0;	
	unsigned  int line_number = 1;
	size_t len = 0;
	char *aux = NULL;
	char *token = NULL;
	if (ac != 2)
	{
		printf("Usage Error\n");
		return 1;
	}
	if((ifp = fopen(av[1], "r")) == NULL)
	{
		printf("Not open the file\n");
		return 1;
	}
	while ((read = getline(&aux, &len, ifp)) != -1)
	{
		if(*aux != '\n')
		{
			if(*aux == ' ')
				token = strtok(aux, DELIM);
			if (*aux != ' ')
				token = strtok(aux, DELIM);
			if (*token == '#')
				continue;
			if (check_push(token) != 0 && token != NULL)
				second = strtok(NULL, DELIM);
			else
				second = NULL;
/*			printf("%s-----%s\n", token,second);*/
			checkFunction(token, line_number, &stack);
			line_number += 1;
		}
	}
	free(aux);
	free_list(stack);
	fclose(ifp);
	return 0;
}
