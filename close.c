#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main() {
	int fildes;

	int r;

	r = close(fildes);

	fprintf(stderr, "%d\n", errno);

	if (r != 0) 
		fprintf(stderr, "Failed to close file %d: %s\n", fildes, strerror(errno));

	fprintf(stderr, "%d\n", errno);

	return 0;
}