#include "header.h"
#define DELIM " \n"

char *token;
char *second;

int main()
{
	FILE *ifp;
	size_t len = 0;
	ssize_t read = 0;	
	unsigned  int line_number = 1;
	char *aux = NULL;
	ifp = fopen("monty.txt", "r");
	while ((read = getline(&aux, &len, ifp)) != -1)
	{
		if(*aux != '\n')
		{
			if(*aux == ' ')
				token = strtok(aux, DELIM);
			if (*aux != ' ')
				token = strtok(aux, DELIM);
			if (*token == '#')
			{
				continue;
			}
			if (check_push(token) != 0 && token != NULL)
				second = strtok(NULL, DELIM);
			else
				second = NULL;
			checkFunction();
			line_number += 1;
		}
	}
	free(aux);
	fclose (ifp);
	return 0;
}
