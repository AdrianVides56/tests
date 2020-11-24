#include "shell.h"

/**
 * _getline - prints the prompt and wait for instructions
 * @val_issaty: value of issaty function
 * Return: the read line
 */
char *_getline(size_t val_issaty)
{
	size_t bufsize = 0, getln = 0;
	char *line = NULL;

	if (val_issaty == 1)
	{
		write(STDOUT_FILENO, "\033[1;32mRASH@SHELL$", 19);
		write(STDOUT_FILENO, "\033[0m]", 4);
	}

	getln = getline(&line, &bufsize, stdin);

	if (getln == EOF)
	{
		_putchar(10);
		exit(EXIT_SUCCESS);
	}
	return (line);
}

/**
 * *_getenv - gets the enviromental variables
 * @myEnvp: pointer to envp in main function
 * @path: string "PATH"
 * Return: the PATH
 */
char *_getenv(char **myEnvp, char *path)
{
	char *envpath;
	int count = 0;

	while (myEnvp[count] != NULL)
	{
		envpath = _strstr(myEnvp[count], path);
		if (envpath == NULL)
			count++;
		else
			return (envpath);
	}
	return (NULL);
}

/**
 * *_strstr - finds the coincidence needle in string haystack
 * @haystack: String to read
 * @needle: string to find in haystack
 * Return: coincident string found int haystack
 */
char *_strstr(char *haystack, char *needle)
{
	char *c;

	while (haystack)
	{
		while (*needle == *haystack)
			haystack++, needle++;
		if (*needle == '\0')
		{
			haystack++;
			c = haystack;
			return (c);
		}
		haystack++;
	}
	return (NULL);
}
/**
 * _execve - executes a file given a path
 * @path: path to follow
 * @command: command to execute
 * @flags: flags of the command
 */
void _execve(char *path, char *command, char **flags)
{
	char *token, *token2[1024], *execute;
	char *tmp, *tmp2;
	const char delim[2] = ":";
	int i = 0;

	tmp = malloc(sizeof(char) * (strlen(path) + 1));
	tmp = strcpy(tmp, path);

	token = strtok(tmp, delim);
	while (token != NULL)
	{
		token2[i] = token;
		token = strtok(NULL, delim);
		i++;
	}

	tmp2 = malloc(sizeof(char) * 64);
	for (i = 0; token2[i] != NULL; i++)
	{
		tmp2 = strcpy(tmp2, token2[i]);
		_strcat(tmp2, "/");
		_strcat(tmp2, command);
		if (execve(tmp2, flags, NULL) == -1)
			continue;
	}
	errors(127);
}
