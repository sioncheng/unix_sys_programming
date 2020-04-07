#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	long maxpath;
	char *pwd;

	if ( -1 == (maxpath = pathconf(".", _PC_PATH_MAX)) ) {
		perror("Failed to determine the pathname length");
		return 1;
	}

	if (NULL == (pwd = (char *)malloc(maxpath))) {
		perror("Failed to allocate space for pathname");
		return 1;
	}

	printf("_PC_PATH_MAX: %ld\n", maxpath);

	if (NULL == getcwd(pwd, maxpath)) {
		perror("Failed to get current working directory");
		return 1;
	}

	printf("Current working directory: %s\n", pwd);

	return 0;
}