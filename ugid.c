#include <stdio.h>
#include <unistd.h>

int main(void) {
	printf("uid: %ld\n", (long)getuid());
	printf("gid: %ld\n", (long)getgid());
	printf("effective uid: %ld\n", (long)geteuid());
	printf("effective gid: %ld\n", (long)getegid());

	return 0;
}