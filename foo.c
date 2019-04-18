#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int 
main(int argc,char *argv[])
{
	int k,n,pid;
	double x = 0,z;

	if(argc < 2)
		n = 1;
	else
		n = atoi(argv[1]);
	
	if(n < 0 || n > 20)
		n = 2;

	x = 0;
	pid = 0;
	for(k = 0;k < n; k++)
	{
		pid = fork();
		if(pid < 0){
			printf(1,"%d failed in fork!\n",getpid());
			exit();
		}else if(pid > 0){ //parent
			printf(1,"Parent %d creating child %d\n",getpid(),pid);	
			wait();
		}else{ //child
			printf(1,"Child %d have created.\n",getpid());
			break;
		}
	}

	for(z = 0;z < 300000.0; z += 0.1)
		x = x+3.14*89.64;
	exit();
}
