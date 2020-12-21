#include "shell.h"

void errors(int errornum)
{
char *errormsg = "Error\n", *notfound = "Command not found\n";

char *errormsg2 = "Error\n", *notfound2 = "allocation error\n";

char *newline = "\n";
	if (errornum == -1)
    	{
      		write(STDOUT_FILENO, errormsg, _strlen(errormsg));
      		exit(EXIT_SUCCESS);
    	}
  	else if (errornum == 0)
    	{
 		write(STDOUT_FILENO, newline, _strlen(newline));
		exit(EXIT_SUCCESS);
	}
	else if (errornum == 127)
	write(STDOUT_FILENO, notfound, _strlen(notfound));

	else if (errornum == 3)
	{
		write(STDOUT_FILENO, errormsg2, _strlen(errormsg2));
                exit(EXIT_SUCCESS);
	}

}
