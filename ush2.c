#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "ush2>>"
#define QUIT "q"

void executecmd(char *incmd);

int main(int argc, char *argv[]) {
	pid_t childpid;
	char inbuf[MAX_CANON];
	int len;

	for (;;) {
		if (fputs(PROMPT, stdout) == EOF) {
			continue;
		}

		if (fgets(inbuf, MAX_CANON, stdin) == NULL) {
			continue;
		}

		len = strlen(inbuf);
		if (inbuf[len - 1] == '\n') {
			inbuf[len - 1] = 0;
		}
		if (strcmp(inbuf, QUIT) == 0) {
			break;
		}
		if ((childpid=fork()) == -1) {
			perror("Failed to fork child");
		} else if (childpid == 0) {
			executecmd(inbuf);
			return 1;
		} else {
			wait(NULL);
		}
	}

	printf("%s\n", "bye!");

	return 0;
}