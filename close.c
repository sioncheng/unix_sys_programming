#include<stdio.h>
#include<unistd.h>

int main() {
	int fildes;

	if (close(fildes) != 0) 
		perror(NULL);

	return 0;
}