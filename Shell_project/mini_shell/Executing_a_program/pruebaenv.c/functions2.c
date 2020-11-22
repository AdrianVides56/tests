#include "shell.h"

char *_getenv(char **myEnvp, char *path)
{
	char *envpath;
	int count = 0;

	while(myEnvp[count] != NULL)
	{
		envpath = _strstr(myEnvp[count], path);
			if (envpath == NULL)
				count++;
			else
			{
				return (envpath);
			}
	}
	return (NULL);
}

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

int _execve(char *path, char *command/*, const char *ep*/)
{
	char *token = NULL, *token2[1024], *execute;
	int i = 0, check = 0;

	token = strtok(path, ":");
	while (token != NULL)
	{
		token2[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	for (i = 0; token2[i] != NULL; i++)
	{
		execute = _strcat(token2[i], command);
		check = execve(execute, token2, NULL);
		printf("{%s}---%d\n", execute, check);
		if (check != -1)
			return (1);
	}
}
