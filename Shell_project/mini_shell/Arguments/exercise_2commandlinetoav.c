#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " "

char **split(char* line)
{
	char *token, **token2;
	int i = 0;

	token = strtok(line, DELIM);

	while (token != NULL)
	{
		token2[i] = token;
		i++;
		token = strtok(NULL, DELIM);
	}
	token2[i] = NULL;

        return (token2);
}
