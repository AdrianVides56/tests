#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define DELIM " ,!¡¿?\'\"\n\t"

int main(void)
{
	char *prompt = "hola@shell$ ", *BUFFER;
	size_t bufsize = 1024;
	pid_t child_pid;
	char *token = NULL, *token2[1024];
	int i = 0;
	unsigned int getln;

	while (1)
	{
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
		if (child_pid == 0)
		{
			if (execve(token2[0], token2, NULL) == -1)
       			{
       				perror("Error");
			}
			exit(0);
		}
		else
			child_pid = wait(NULL);
	}
	return (0);
}
