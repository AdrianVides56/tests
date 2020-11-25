#include "shell.h"

/**
 * errors - check for errors
 * @errornum: number of error
 */
void errors(int errornum)
{
	char *errormsg = "Error\n", *notfound = "Command not found\n";
	char __attribute__((unused)) *newline = "\n";

	if (errornum == -1)
	{
		write(STDOUT_FILENO, errormsg, _strlen(errormsg));
		exit(EXIT_SUCCESS);
	}
	else if (errornum == 0)
		exit(EXIT_SUCCESS);

	else if (errornum == 127)
		write(STDOUT_FILENO, notfound, _strlen(notfound));
	else if (errornum == 126)
		write(STDOUT_FILENO, "Failed Malloc", _strlen("Failed malloc"));
}
