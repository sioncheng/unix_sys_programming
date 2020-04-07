#include <stdio.h>
#include <unistd.h>

int main(void) {
	int x ;

	x = 0;
	fork();
	x = 1;


	printf("pid: %d, x: %d\n", getpid(), x);

	return 0;
}