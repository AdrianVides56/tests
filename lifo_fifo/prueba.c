#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DELIM " \n"
char *token;
int check_push(char *s);
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
				continue;
			while(token != NULL && check_push(token) != 0)
			{
				token = strcat(token, strtok(NULL, DELIM));
			}
			line_number += 1;
		}
	}
	free(aux);
	fclose (ifp);
	return 0;
}
int check_push(char *s)
{
	char *accept = "push";
	int i = 0;
	if (s == NULL)
	{
		return 0;
	}
	while(s[i] == accept[i])
        {
            i++;
        }
        if (i == 5 && s[i] == ' ')
	{
		return 1;
	}
        return 0;
}
