#include<stdio.h>

int c(const int *a, int *b) {
	//*a = 1;
	*b = 2;
	a = b;
	return 0;
}

int rc(int *restrict a, int *b) {
	*a = 11;
	*b = 22;
	return 0;
}

int cc(int *const c, int *b) {
	*b = 3;
	*c = 4;
	//c = b;
	return 0;
}

int main() {

	int *i;

	c(i, i);

	fprintf(stdout, "%d\n", *i);

	rc(i, i);

	fprintf(stdout, "%d\n", *i);

	cc(i, i);

	fprintf(stdout, "%d\n", *i);

	return 0;
}