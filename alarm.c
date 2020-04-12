#include <unistd.h>

int main(int argc, char *argv[]) {
	alarm(10);
	for(;;);
}