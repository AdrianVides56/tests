#include "shell.h"

/**
 * main - simulates a shell
 * @argc: number of arguments passed to the function
 * @argv: argument passed to the function
 * @envp: enviroment pointer
 * Return: 0 Success
 */
int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv,
	 char **envp)
{
	char *line = NULL;
	char *token = NULL, **token2 = NULL, *path = NULL;
	size_t i = 0;
	pid_t child_pid;

	while (1)
	{
		i = isatty(STDOUT_FILENO);
		line = _getline(i);
		if (strcmp(line, "exit\n") == 0)
			errors(0);
		token = strtok(line, DELIM);
		token2  = malloc(sizeof(char *) * _strlen(line));
		if (token2 == NULL)
			errors(126);
		for (i = 0; token != NULL; i++)
		{
			token2[i] = token;
			token = strtok(NULL, DELIM);
		}
		child_pid = fork();
		if (child_pid == -1)
			errors(-1);
		if (child_pid == 0)
		{
			path = _getenv(envp, "PATH");
			if (execve(line, token2, NULL) == -1)
				_execve(path, token2[0], token2);
		}
		else
			 wait(NULL);
		for (i = 0; token2[i] != NULL; i++)
			free(token2[i]);
		free(token2);
	}
		free(line);
	return (0);
}
