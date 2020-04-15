#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	sigset_t set;

	sigemptyset(&set);

	printf("%d\n", set);

	// sigfillset(&set);

	// printf("%d\n", set);	

	sigaddset(&set, 15);

	printf("%d\n", set);

	printf("%d\n", sigismember(&set, 15));

	sigdelset(&set, 15);

	printf("%d\n", set);

	printf("%d\n", sigismember(&set, 15));

	return 0;
}