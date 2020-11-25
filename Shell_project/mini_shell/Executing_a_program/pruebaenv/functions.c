#include "shell.h"

/**
 * *_strcat - concatenates two strings
 * @dest: destiny string
 * @src: source string
 * Return: new string
 */
char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++)
		;
	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a] = src[b];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * *_strlen - returns the lenght of a string
 * @str: string
 * Return: length of th string
 */
size_t _strlen(char *str)
{
	size_t len = 0;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * \*_strcpy - copy a string in other string
 * @dest: string
 * @src: string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';
	return (dest);
}
