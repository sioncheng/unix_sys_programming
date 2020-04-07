#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

	struct stat statbuf;

	if (argc < 2) {
		perror("Usage: stat path");
		return 1;
	}

	if (-1 == (stat(argv[1], &statbuf))) {
		fprintf(stderr, "Failed to determine stat of %s\n", argv[1]);
		return 1;
	}

	if (S_ISDIR(statbuf.st_mode)) {
		printf("%s is direcotry\n", argv[1]);
	} 
	if (S_ISREG(statbuf.st_mode)) {
		printf("%s is regular file\n", argv[1]);
	}

	return 0;
}