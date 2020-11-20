#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define GREEN_T "\x1b[32m"
#define RESET_COLOR "\x1b[37m"

#define DELIM " ,!¡¿?\'\"\n\t"
char *_strcat(char *dest, char *src);

extern char **environ;

static char *my_envp[100];
int attach_path(char *cmd);
void get_path_string(char **tmp_envp, char *bin_path);
void insert_path_str_to_search(char *path_str);
void copy_envp(char **envp);


int main(int ac, char **av, char **envp)

{

        char *prompt = "hola@shell$ ", *BUFFER;
        size_t bufsize = 1024;
        pid_t child_pid;
        char *token = NULL, *token2[1024];
        int reset, i;
        unsigned int getln;

        while (1)
        {
                i = 0;
                reset = 0;
		char *path_str = (char *)malloc(sizeof(char) * 256);
                char path[60] = "/bin/";
                char path2[20] = "/sbin/";
		int b;
                if (isatty(STDOUT_FILENO) == 1)
                        printf(GREEN_T "%s" RESET_COLOR, prompt);

                getln = getline(&BUFFER, &bufsize, stdin);
                if (getln == EOF)
                {
                        printf("exit\n");
                        printf("\n");
                        exit(EXIT_SUCCESS);
                }

                token = strtok(BUFFER, DELIM);


		copy_envp(envp);
		get_path_string(my_envp, path_str);
		
		for(b = 0;  environ[b]!= '\0' ; b++)
		{
		printf("{%s}\n", environ[b]);
		}
                while (token != NULL)
                {
                        token2[i] = token;
                        token = strtok(NULL, DELIM);
                        i++;
                }
                if (token2[0] != NULL)
                {
                        if(strcmp(token2[0], "exit") == 0)
                        {
                                printf("\n-"); //PRODUCE DOS SALTOS DE LINEA
                                exit(0);
                        }
                }
                child_pid = fork();
                if (child_pid == -1)
                {
                        perror("Error");
                        return (1);
                }
                if (child_pid == 0)
                {
                        execve(_strcat(path, token2[0]), token2, NULL);
                        execve(_strcat(path2, token2[0]), token2, NULL);

                        exit(0);
                }
                else
                        child_pid = wait(NULL);
                for (;reset <= i; reset ++)
                        token2[reset] = NULL;
        }
        return (0);
}

char *_strcat(char *dest, char *src)
{
        int a, b;

        for (a = 0; dest[a] != '\0'; a++)
        {
        }
        for (b = 0; src[b] != '\0'; b++)
        {
        dest[a] = src[b];
        a++;
        }
        dest[a] = '\0';
        return (dest);
}
/*
int attach_path(char *cmd)
{
	char ret[100];
	int index;
	int fd;
	bzero(ret, 100);
	for(index=0;search_path[index]!=NULL;index++) {
		strcpy(ret, search_path[index]);
		strncat(ret, cmd, strlen(cmd));
		if((fd = open(ret, O_RDONLY)) > 0) {
			strncpy(cmd, ret, strlen(ret));
			close(fd);
			return 0;
		}
	}
	return 0;
}
*/
void get_path_string(char **tmp_envp, char *bin_path)
{
	int count = 0;
	char *tmp;
	while(1) {
		tmp = strstr(tmp_envp[count], "PATH");
		if(tmp == NULL) {
			count++;
		} else {
			break;
		}
	}
        strncpy(bin_path, tmp, strlen(tmp));
}
/*
void insert_path_str_to_search(char *path_str) 
{
	int index=0;
	char *tmp = path_str;
	char ret[100];

	while(*tmp != '=')
		tmp++;
	tmp++;

	while(*tmp != '\0') {
		if(*tmp == ':') {
			strncat(ret, "/", 1);
			search_path[index] = (char *) malloc(sizeof(char) * (strlen(ret) + 1));
			strncat(search_path[index], ret, strlen(ret));
			strncat(search_path[index], "\0", 1);
			index++;
			bzero(ret, 100);
		} else {
			strncat(ret, tmp, 1);
		}
		tmp++;
	}
}
*/
void copy_envp(char **envp)
{
	int index = 0;
	for(;envp[index] != NULL; index++) {
		my_envp[index] = (char *)malloc(sizeof(char) * (strlen(envp[index]) + 1));
		memcpy(my_envp[index], envp[index], strlen(envp[index]));
	}
}
