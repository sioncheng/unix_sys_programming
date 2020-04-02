#include <stdio.h>
#include <stdlib.h>

void my_exit(void) {
	printf("%s\n", "exit");
}


int main(void) {

	atexit(my_exit);


	printf("%s\n", "hello");
}