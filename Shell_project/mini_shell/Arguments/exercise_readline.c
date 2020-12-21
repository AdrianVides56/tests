#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av)
{
        char *prompt = "hola@shell$ ", *line;
        size_t len = 0;

        while (1)
        {
                printf("%s", prompt);
		if ((getline(&line, &len, stdin) == EOF))
		{
			printf("\n");
			exit(EXIT_SUCCESS);			       	/** here we use stdin since we 
										  * are not receiving input from a file but keyboard
										  * also we don't need the ac and av arguments, 
										  * because the getline will get the input from 
										  * the user
										 **/
		}
		printf("%s", line);
        }

        return 0;
}
