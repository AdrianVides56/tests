#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_push(char *s);
int main()
{
	FILE *ifp;
	const char s[2] = " \n";
	size_t len = 0;
	ssize_t read = 0;	
	/*int j = 0;*/
	unsigned  int line_number = 1;
	char *aux = NULL, *token = NULL;
	ifp = fopen("monty.txt", "r");
	while ((read = getline(&aux, &len, ifp)) != -1)
	{
		if(*aux != '\n')
		{
			printf("Line[%d] = ", line_number);
			if(*aux == ' ')
				token = strtok(aux, s);
			if (*aux != ' ')
				token = strtok(aux, s);
			while(token != NULL && check_push(token) != 0)
			{
				printf("%s ", token);
				token = strtok(NULL, s);
				/*
				if(j > 0)
				{
					j = 0;
					break;
				}*/
			/*j++;*/
			}
			line_number += 1;
			printf("\n");
		}
	}
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
