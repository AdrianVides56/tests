#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    pid_t pid1, pid2, pid3, pid4, pid5;
    int status1, status2, status3, status4,status5;
 
    if ( (pid1=fork()) == 0 )
    { /* hijo */
        printf("Soy el primer hijo (%d, hijo de %d)\n",  getpid(), getppid());
    }
    else
    { /*  padre */
        if ( (pid2=fork()) == 0 )
        { /* segundo hijo  */
            printf("Soy el segundo hijo (%d, hijo de %d)\n",  getpid(), getppid());
	}
	else
	{ /* tercer hijo*/
		if ((pid3=fork()) == 0)
		{
		printf("Soy el tercer hijo (%d, hijo de %d)\n",  getpid(), getppid());
		}
		else
		{ /*4to hijo*/
			if ((pid4=fork()) == 0)
                	{
                	printf("Soy el cuarto hijo (%d, hijo de %d)\n",  getpid(), getppid());
			}
			else
                	{ /*5to hijo*/
                        	if ((pid5=fork()) == 0)
                        	{
                        	printf("Soy el quito hijo (%d, hijo de %d)\n",  getpid(), getppid());
				}
				 else
 				{ /* padre */
					/* Esperamos al primer hijo */
            				waitpid(pid1, &status1, 0);
					/* Esperamos al segundo hijo */
           				waitpid(pid2, &status2, 0);
					/* Esperamos al terce hijo */
            				waitpid(pid3, &status3, 0);
					/* Esperamos al cuarto hijo */
            				waitpid(pid4, &status4, 0);
					/* Esperamos al quinto hijo */
            				waitpid(pid5, &status5, 0);
            			printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
        			}
    			}
		}
	}
}
 
    return 0;
}
