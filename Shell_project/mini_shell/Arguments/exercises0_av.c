#include <stdio.h>
#include <unistd.h>
/**
 * main - program that prints all the arguments, without using ac
 * @ac: ac is the number of items in av
 * @av: av is a NULL terminated array of strings
 *
 * Return: sucess
 */

int main(int ac, char **av)
{
	/** We use double pointer here to not loose the address 
	  of the original array **/

        int a;
        for(a = 0; av[a] != '\0'; a++)
        {
                printf("%s\n", av[a]);
        }
        return 0;
}
