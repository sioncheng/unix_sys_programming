#include<string.h>
#include<stdio.h>

int main(int args, char *argv[]) {
	
	char *ss = "abc";
	char ss2[] = {'a', 'b', 'c', '\0', '\0'};

	printf("%lu %s\n", strlen(ss2), ss2);

	return 0;
}