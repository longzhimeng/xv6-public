#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int 
main(int argc, char *argv[])
{
	int priority,pid;
	
	if(argc < 3){
		printf(2,"Usage:nice pid priorty\n");
		exit();
	}

	pid = atoi(argv[1]);
	priority = atoi(argv[2]);
	//printf(1,"pid=%d,priority=%d\n",pid,priority);

	if(priority < 0 || priority > 20){
		printf(2,"Invalid priority(0-20)!\n");
		exit();
	}

	chpr(pid,priority);

	exit();
	return 0;
}
