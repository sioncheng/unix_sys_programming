#include <stdio.h>
#include <unistd.h>

int main() {

	int x, cid;

	x = 0;

	cid = fork();

	if (-1 == cid) {
		fprintf(stderr, "%s\n", "faild to fork");
		return 1;
	}

	x = 1;

	if (0 == cid) {
		printf("child process %d %d\n", getpid(), x);
	} else {
		printf("parent process %d %d\n", getpid(), x);
	}


	return 0;
}