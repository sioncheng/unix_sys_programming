#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static sig_atomic_t signal_received = 0;

void do_alarm(int n) {
	static int c = 0;

	if (1 == (c++)) {
		printf("%s\n", "... signal received");
		signal_received = 1;
	} else {
		printf("%s\n", "... not yet");
	}
}

int main(int argc, char *argv[]) {

	signal(SIGALRM, do_alarm);

	alarm(1);

	while (1) {
		if (0 == signal_received) {
			printf("%s\n", "... pause");
			alarm(1);
			pause();
		} else {
			printf("%s\n", "... break");
			break;
		}
	}

	return 0;
}