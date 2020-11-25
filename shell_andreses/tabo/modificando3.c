#include "holberton.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *_strcat(char *dest, char *src);
int main(int ac, char **av, char **envp)
{
        char *prompt = "hola@shell$ ", *buffer = NULL;
        size_t bufsize = 1024;
        pid_t child_pid;
        int reset, i, getln;
	char *mypath, **tokenized;
	struct stat st;
	char *temp = NULL;
	char *token = NULL;
	char *combinar;
	const char s[2] = ":"; 
        while (1)
	{
                i = 0;
                reset = 0;
                if (isatty(STDOUT_FILENO) == 1)
                        _puts(prompt);
                getln = getline(&buffer, &bufsize, stdin);
                if (getln == EOF)
                {
                        printerror(1, NULL);
                }
                tokenized = tokenize(buffer);
                if (tokenized[0] != NULL && (_strcmp(tokenized[0], "exit") == 0) )
                {
                                printf("\n"); 
                                exit(0);
                }
		mypath = _getenv("PATH");

                child_pid = fork();

                if (child_pid == -1)
                        return 1;
                if (child_pid == 0)
                {
			if (tokenized[0] != NULL)
			{
				if (stat(tokenized[0], &st) == 0)
				{
					printf(" FOUND\n");	
					execve(tokenized[0], tokenized, NULL);
				}
        				temp  =  malloc(sizeof(char ) * (strlen(mypath) + 1));
			        	temp = strcpy(temp, mypath);
		        		token = strtok(temp, s);
			   	while( token != NULL )
        			{
					combinar = malloc(sizeof(char) * (strlen(token) + strlen(tokenized[0]) + 2));
					combinar = strcpy(combinar, token);
					combinar = _strcat(combinar, tokenized[0]);
					printf("%s\n", combinar);
					execve(combinar, tokenized, NULL);
			        	token = strtok(NULL, s);
          			}
			        free(temp);
    			}	
                }
                else
                         wait(NULL);
				(void)i;
		(void)reset;
		(void)ac;
		(void)av;
		(void)envp;
        }
        return (0);
}
char *_strcat(char *dest, char *src)
{
        int a, b;

        for (a = 0; dest[a] != '\0'; a++)
        {
        }
	dest[a] = '/';
	a++;
        for (b = 0; src[b] != '\0'; b++)
        {
        dest[a] = src[b];
        a++;
        }
        dest[a] = '\0';
        return (dest);
}
