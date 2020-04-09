#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFSIZE 10

int main(int argc, char *argv[]) {
	char bufin[BUFSIZE] = "empty";
	char bufout[] = "hello";
	int bytesin;
	pid_t childpid;
	int fd[2];
	pid_t pid;

	if (pipe(fd) == -1) {
		perror("Failed to create the pipe");
		return 1;
	}

	childpid = fork();
	if (childpid == -1) {
		perror("Failed to fork");
		return 1;
	} 

	bytesin = strlen(bufin);

	if (childpid) {
		write(fd[1], bufout, strlen(bufout) + 1);
	} else {
		bytesin = read(fd[0], bufin, BUFSIZE);
	}

	pid = getpid();
	fprintf(stderr, "pid %ld childpid %ld \n", (long)pid, (long)childpid);

	if (childpid) {
		fprintf(stderr, "parent [%ld]:my bufin is {%.*s}, my bufout is {%s}\n", 
			(long)pid, bytesin, bufin, bufout);
	} else {
		fprintf(stderr, "child [%ld]:my bufin is {%.*s}, my bufout is {%s}\n", 
			(long)pid, bytesin, bufin, bufout);
	}

	return 0;
}