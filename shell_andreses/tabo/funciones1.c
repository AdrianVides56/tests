#include "holberton.h"
extern char **environ;

char *_strstr(char *haystack, const char *needle)
{
	char *c;
	while (*haystack)
	{
		while (*needle == *haystack)
		{
			haystack++, needle++;
		}
		if (*needle == '\0')
		{
			if(*haystack == '=')
			{
				haystack++;
				c = haystack;
				return c;
			}
			return (NULL);
		}
		haystack++;
	}
	return (NULL);
}

char *_getenv(const char *name)
{

	char *mi_envp;
        int index = 0;
	while(environ[index] != '\0')
	{
		mi_envp = _strstr(environ[index], name);
		if (mi_envp == NULL)
			index++;
		else
			return mi_envp;
       	}
	return NULL;
}


int len(const char *str)
{
    int count;

    if (str == NULL)
        return (0);
    for (count = 0; str[count] != '\0'; count++)
        ;
    return (count);
}

char **tokenize(char *buffer)
{
	int words, i;
	char *token, **token2;
	words = count_words(buffer);
	if(words == 0)
		{
		return NULL;
		}
	token = strtok(buffer, DELIM);
	token2 = malloc(sizeof(char *) * (words + 1));

	while (token != NULL)
	{
		token2[i] = (char*)malloc(sizeof(char) * (_strlen(token) + 1));
		token2[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	return (token2);
}

int _strlen(char *s)
{
	int l;

	for (l = 0; s[l] != '\0'; l++)
		{
	}
	return (l);
}
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
		if (s1[i] == '\0')
			return (0);
	return (s1[i] - s2[i]);
}
int _putchar(char c)
{
		return (write(1, &c, 1));
}
void printerror(int error, char *command)
{
	if (error == 2)
	{
		_puts(command);
		_puts(": No such file or directory\n");
		exit(error);
	}
	if (error == 126)
	{
		_puts(command);
		_puts(": Required key not available\n");
		exit(error);
	}
	if (error == 127)
	{
		_puts(command);
		_puts(": Key has expired\n");
		exit(error);
	}
	if (error == 1)
	{
		_puts("exit\n");
		_puts("\n");
		exit(EXIT_SUCCESS);
	}

}
void free_grid(char **grid)
{
	int i;

	for (i = 0; grid[i] != NULL ; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
int word_len(char *str)
{
	int index = 0, len = 0;

	while (*(str + index) && *(str + index) != ' ')
	{
		len++;
		index++;
	}

	return (len);
}

int count_words(char *str)
{
	int index = 0, words = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;

	for (index = 0; index < len; index++)
	{
		if (*(str + index) != ' ')
		{
			words++;
			index += word_len(str + index);
		}
	}

	return (words);
}
