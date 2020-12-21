#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define DELIM " ,!¡¿?\'\"\n\t"
char *_strcat(char *dest, char *src);
int main(void)
{
	char *prompt = "hola@shell$ ", *BUFFER;
	size_t bufsize = 1024;
	pid_t child_pid;
	char *token = NULL, *token2[1024];
	int reset, i;
	unsigned int getln;

	while (1)
	{
		i = 0;
		reset = 0;
		char path[60] = "/bin/";
		printf("%s", prompt);

		getln = getline(&BUFFER, &bufsize, stdin);
		if (getln == EOF)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		token = strtok(BUFFER, DELIM);
		while (token != NULL)
       		{
       			token2[i] = token;
       			token = strtok(NULL, DELIM);
       			i++;
       		}
		
		child_pid = fork();
		if (child_pid == -1)		
		{
			perror("Error");
			return (1);
		}
		_strcat(path, token2[0]);
		printf("Postion 1:%s---Position 2: %s-----path: %s\n", token2[0], token2[1], path);
		if (child_pid == 0)
		{
			if (execve(path, token2, NULL) == -1)
       			{
       				perror("Error");
			}
			exit(0);
		}
		else
			child_pid = wait(NULL);
		for (;reset <= i; reset ++)
			token2[reset] = NULL;
	}
	return (0);
}
char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++)
	{
	}
	for (b = 0; src[b] != '\0'; b++)
	{
	dest[a] = src[b];
	a++;
	}
	dest[a] = '\0';
	return (dest);
}
