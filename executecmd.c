#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BLANK " "

int makeargv(const char *s, const char *delimiters, char ***argvp);

void executecmd(char *incmd) {
	char **chargv;

	if (makeargv(incmd, BLANK, &chargv) <= 0) {
		fprintf(stderr, "Failed to parse command line\n");
		exit(1);
	}

	execvp(chargv[0], chargv);
	perror("Failed to execute command");
	exit(1);
}