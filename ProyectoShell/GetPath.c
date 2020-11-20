#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char * getpath(char **tmp_envp, char *bin_path)
{
int i = 0;
char *tmp;
	while(1)
	{
		tmp = strstr(tmp_envp[i], "PATH");
		if (tmp == NULL)
		{
			i++;
		}
		else
		{
			break;
		}
	}
	strncpy(bin_path, tmp, strlen(tmp));
	return (bin_path);
}

