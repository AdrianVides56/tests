#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " "

int *split(char *line)
{
	char *token, *token2;
	int i = 0;

	token = strtok(line, DELIM);

	while (token != NULL)
	{	
		token2[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	tokens2[i] = NULL;
	return (tokens2);
}
