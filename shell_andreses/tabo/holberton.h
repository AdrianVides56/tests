#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define DELIM " ,!¡¿?\'\"\n\t"
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */

char **_getpath(const char *name);
char *_getenv(const char *name);
int len(const char *str);
char *_strstr(char *haystack, const char *needle); 
char **tokenize(char *buffer);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);
void printerror(int error, char *command);
int word_len(char *str);
int count_words(char *str);
#endif
