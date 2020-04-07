#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 255
#endif

int main(void) {
	char pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX) == NULL) {
		perror("Failed to get current working directory");
		return 1;
	}

	printf("Current working directory: %s\n", pwd);

	return 0;
}