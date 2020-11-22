#include "shell.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char *_getnenv(char *name)
{
char *mi_envp;
int index = 0;

	while(*environ[index] != '\0')
	{
		mi_envp = _strstr(environ[index], name);
		if (mi_envp == NULL)
			index++;
		else
			return mi_envp;
	}
return NULL;
}


