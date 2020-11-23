#include "shell.h"

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
 * @envi: enviromental variable
 */
void _execve(char *path, char *command, char **flags, char __attribute__((unused)) **envi)
{
	char *token = NULL, *token2[1024], *execute = NULL;
	int i = 0;

	token = strtok(path, ":");
	while (token != NULL)
	{
		token2[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	token2[i] = NULL;

	for (i = 0; token2[i] != NULL; i++)
	{
		execute = NULL;
		_strcat(token2[i], "/");
		/*execute = _strcat(token2[i], command);*/

		if (execve(execute, flags, NULL) == -1)
			continue;
       		/* printf("Execute path: %s\n", execute);
		 if (check == -1)
		  printf("%s\n", execute);*/
	}
}
