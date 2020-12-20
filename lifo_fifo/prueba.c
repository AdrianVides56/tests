#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int j =0;
	FILE *ifp;
	const char s[2] = " \n";
	size_t len = 0;
	ssize_t read = 0;	
	unsigned  int line_number = 1;
	char *aux = NULL, *token = NULL;
	/*const char opcode = ["push", "pall", "pint", "pop", "swap"];**/
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
			while(token != NULL && strcpm(token, "push") == 0)
			{
				printf( " %s", token);
				token = strtok(NULL, s);
				if (j > 0 &&)
				{
					j = 0;
					break;
				}
			j++;
			}
			line_number += 1;
			printf("\n");
		}
	}
	fclose (ifp);
	return 0;
}
