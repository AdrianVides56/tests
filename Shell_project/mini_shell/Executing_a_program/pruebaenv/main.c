#include "shell.h"

/**
 * main - simulates a shell
 * @argc: number of arguments passed to the function
 * @argv: argument passed to the function
 * @envp: enviroment pointer
 * Return: 0 Success
 */
int main(int argc, char **argv, char **envp)
{
	char *prompt = "hola@shell$ ", *line;
	char *token = NULL, *token2[1024], *path;
	size_t bufsize = 1024, getln;
	pid_t child_pid;
	int reset, i;

	while (1)
	{
		i = 0;
		reset = 0;
		isatty(STDOUT_FILENO);
		printf(GREEN_T "%s" RESET_COLOR, prompt);
		getln = getline(&line, &bufsize, stdin);
		if (getln == EOF || (strcmp(line, "exit\n") == 0))
			errors(0);
		token = strtok(line, DELIM);
		while (token != NULL)
		{
			token2[i] = token;
			token = strtok(NULL, DELIM);
			i++;
		}
		child_pid = fork();
		if (child_pid == -1)
			errors(-1);
		if (child_pid == 0)
		{
			path = _getenv(envp, "PATH");
//			printf("%s\n", path);
			_execve(path, token2[0], token2);

		}
		else
		{
			 wait(NULL);
		}
		for (reset = 0; reset <= i; reset++)
			token2[reset] = NULL;
	}
	return (0);
}
