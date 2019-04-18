#include "types.h"
#include "stat.h"
#include "user.h"

void
periodic()
{
	printf(1,"alarm\n");

}

int 
main(int argc,char *argv[])
{
	int i;
	printf(1,"alarmtest starting\n");
	alarm(5,periodic);
	for(i = 0; i < 500 * 500000;i++){
		if((i++ % 500000) == 0)
			write(2,".",1);	
	}

	exit();
}
