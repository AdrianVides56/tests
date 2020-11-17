#include "shell.h"

int main(int ac, char *av[])
{
	char *line = NULL, *args, *prompt = "hola$ ";
	ssize_t bufsize = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));

		if (getline(&line, &bufsize, stdin) == -1)
		{
			if (EOF)
				exit(EXIT_SUCCESS);
/*			else
			{
				perror("lsh: getline\n");
				exit(EXIT_FAILURE);
*/			}
		}
	}
}
