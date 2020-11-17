#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
	pid_t my_pid, parent;

	parent = getppid();
	my_pid = getpid();
	printf("Child: %u\n", my_pid);
	printf("Parent: %u\n", parent);

//	kill(parent, 1247);
	return (0);
}
