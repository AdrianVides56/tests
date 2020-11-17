#include <stdio.h>
#include <stdlib.h>

int main(/*int ac, char *av*/)
{
        char *prompt = "hola@shell$ ", *line;
        size_t len = 0;

        while (1)
        {
                printf("%s", prompt);
                getline(&line, &len, stdin);
                printf("%s", line);
        }

        return 0;
}
