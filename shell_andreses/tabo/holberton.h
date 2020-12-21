#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define DELIM " ,!¡¿?\'\"\n\t"


char *_getenv(const char *name);
char *_strstr(char *haystack, const char *needle); 
char **tokenize(char *buffer);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);
void printerror(int error, char *command);
int word_len(char *str);
int count_words(char *str);
void free_grid(char **grid);
#endif
