#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *split(char* line)
{
        const char s[2] = " ";
	char *token, *token2[strlen(line)];
	int i = 0;

	token = strtok(line, s);
	token2[i] = token;

	while (token != NULL)
	{
		token = strtok(NULL, s);
		i++;
		token2[i] = token;
	}

        return (*token2);
}
