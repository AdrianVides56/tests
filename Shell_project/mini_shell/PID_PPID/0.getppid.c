#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
/**
  * main - prints the PID of the parent process
  * 
  * Return: 0 if success
**/
int main()
{
	pid_t parent_id = getppid(); /**Get parent process id**/

	printf("%d\n", parent_id);

	return (0);
}
