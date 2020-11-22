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

int _strlen(char *str)
{
  int len = 0;

  for (len = 0; str[len] != '\0'; len++)
    ;
  return (len);
}


/**
 * *_strstr-Entry point
 * @haystack: is a variable pointer
 * @needle: is a variable pointer
 * @
 *  Return: Always 0.
 */
char *_strstr(char *haystack, char *needle)
{
char *a, *c;

        while (*haystack)
        {
                c = haystack;
                a = needle;
                while (*a == *haystack && *a)
                {
                        haystack++, a++;
                }
                if (*a == '\0')
                        return (c);
                haystack = c + 1;
        }
        return (0);
}
