#include<stdio.h>
#include<string.h>

int checkpass(void) {
	int x;
	char a[9];
	x = 0;

	fprintf(stderr, "a at %p\nx at %p\n", (void *)a, (void *)&x);

	printf("enter password:\n");

	scanf("%s", a);

	if (strcmp("mypass", a) == 0) {
		x = 1;
	}

	return x;
}

int main() {

	int r = checkpass();
	printf("%d\n", r);

	return 0;
}