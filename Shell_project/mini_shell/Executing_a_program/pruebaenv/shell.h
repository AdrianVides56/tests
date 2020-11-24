#ifndef SHELL_H
#define SHELL_H

#define DELIM " ,!¡¿?\'\"\n\t"
#define GREEN_T "\x1b[32m"
#define RESET_COLOR "\x1b[37m"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char *_strcat(char *dest, char *src);
char **_strtok(char *line);
size_t _strlen(char *str);
void errors(int errornum);
int _putchar(char c);
char *_getline(size_t val_issaty);
void _execve(char *path, char *command, char **flags);
char *_getenv(char **myEnvp, char *path);
char *_strstr(char *haystack, char *needle);

#endif
