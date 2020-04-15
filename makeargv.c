#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>


int makeargv(const char *s, const char *delimiters, char ***argvp) {
	int num_of_tokens;

	int error;
	int i;
	const char *snew;
	char *t;

	if ((NULL == s) || (NULL == delimiters) || (NULL == argvp)) {
		errno = EINVAL;
		return -1;
	}

	*argvp = NULL;
	snew = s + strspn(s, delimiters);
	
	if (NULL == (t = malloc(strlen(snew) + 1))) {
		return -1;
	}

	strcpy(t, snew);
	num_of_tokens = 0;
	if (NULL != strtok(t, delimiters)) {
		for (num_of_tokens = 1; NULL != strtok(NULL, delimiters); num_of_tokens++);
	}

	if (0 == num_of_tokens) {
		free(t);
		return 0;
	}

	if (NULL == (*argvp = malloc((num_of_tokens + 1) * sizeof(char *)))) {
		error = errno;
		free(t);
		errno = error;
		return -1;
	}

	strcpy(t, snew);
	**argvp = strtok(t, delimiters);
	for (i =1 ; i < num_of_tokens; i++) {
		*((*argvp) + i) = strtok(NULL,delimiters);
	}
	*((*argvp) + num_of_tokens) = NULL;

	return num_of_tokens;
}

// int main(int argc, char *argv[]) {

// 	int n = 0;
// 	char **argvp = NULL;

// 	n = makeargv("main -c 100 -d 200", " ", &argvp);

// 	fprintf(stdout, "%d\n", n);

// 	for (int i = 0; i < n; ++i){
// 		printf("%s\n", *(argvp + i));
// 	}

// 	return 0;
// }