#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
	pid_t p = 0;	
	for(int i = 0; i < 5; i++)
		fork();	
	p = getpid();
	printf("%i\n", p);
	sleep(1);
	return 0;
}
