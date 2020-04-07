#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	//execl("/bin/ls", "ls", "-l", NULL);

	execlp("ls", "ls", "-l", NULL);

	return 0;
}