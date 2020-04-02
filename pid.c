#include <stdio.h>
#include <unistd.h>

int main(void) {
	printf("pid: %ld \n", (long)getpid());
	printf("ppid: %ld \n", (long)getppid());

	return 0;
}