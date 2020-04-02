#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listlib.h"

#ifndef MAX_CANON
#define MAX_CANON 8192
#endif

int runproc(char *cmd) {
	data_t execute;

	if (-1 == time(&(execute.time))) {
		return -1;
	}
	execute.string = cmd;

	if (system(cmd) == -1) {
		return -1;
	}

	return adddata(execute);
}

void showhistory(FILE *f) {
	data_t data;
	int key;

	key = accessdata();
	if (-1 == key) {
		fprintf(f, "%s\n", "No history");
		return;
	}

	while (!getdata(key, &data) && (NULL != data.string)) {
		fprintf(f, "Command: %s\t Time: %s\n", data.string, ctime(&(data.time)));
		free(data.string);
	}

	freekey(key);
}

int main(int argc, char *argv[]) {
	char cmd[MAX_CANON];
	int history = 1;

	if (argc == 1) {
		history = 0;
	} else if ( argc >= 2 && (0 != strcmp(argv[1], "history")) ){
		fprintf(stderr, "Usage: %s [history]\n", argv[0]);
		return 1;
	}

	while (NULL != fgets(cmd, MAX_CANON, stdin)) {
		if ('\n' == *(cmd + strlen(cmd) - 1)) {
			*(cmd + strlen(cmd) - 1) = 0;
		}

		if (history && !strcmp(cmd, "history")) {
			showhistory(stdout);
		} else if (runproc(cmd)) {
			perror("Failed to execute Command");
			break;
		}
	}

	printf("\n\n>>>>>>>> The list of commands executed is:\n");
	showhistory(stdout);


	return 0;


}