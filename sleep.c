#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void doint(int n) {
	printf("signal %d\n", n);
}

unsigned int _sleep(unsigned int s) {
	unsigned int rest;

	alarm(s);
	pause();

	rest =  (alarm(0));

	printf("%d\n", rest);

	return rest;
}

int main(int argc, char *argv[]) {

	signal(SIGALRM, doint);

	while(1) {
		_sleep(10);
		printf("%s\n", "...zzZ");
	}

	return 0;
}