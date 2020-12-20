#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char *aux, *token;
	int j = 0;
	FILE *ifp;
	const char s[2] = " \n";
	unsigned int line_number = 1;
	/*const char opcode = ["push", "pall", "pint", "pop", "swap"];**/
	ifp = fopen("../monty.txt", "r");
	strcpy(aux, "");
	while( 1)
	{
		if (fgets(aux, 1024, ifp) != NULL)
		{
			if(strcmp(aux, "\n\0") != 0 )
			{
				printf("Line[%d] = ", line_number);
				aux = strtok(aux, s);
				token = strtok(aux, s);   
				printf("%s--------", aux);
				while( token != NULL )
				{
					/*printf( " %s ", token);*/
					token = strtok(NULL, s);
					if (j > 0)
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
		else
			break;
	}
	fclose (ifp);
	return 0;
}
