#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	pid_t childpid;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s command arg1 arg2 ...\n", argv[0]);
		return 1;
	}

	childpid = fork();
	if (-1 == childpid) {
		perror("Failed to fork");
		return 1;
	}

	if (0 == childpid) {
		execvp(argv[1], &argv[1]);
		perror("Child failed to execvp the command");
		return 1;
	}

	if (childpid != wait(NULL)) {
		perror("Parent failed to wait");
		return 1;
	}

	return 0;
}