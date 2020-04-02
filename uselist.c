#include <stdio.h>
#include <time.h>
#include "listlib.h"

int main(int argc, char *args[])  {

	int k;
	int g;
	data_t dt;
	data_t dtg;

	dt.time = time(NULL);
	dt.string = "abcdefg";

	adddata(dt);

	dt.time = time(NULL);
	dt.string = "123456";

	adddata(dt);


	k = accessdata();
	printf("%d\n", k);

	g = getdata(k, &dtg);
	printf("%d %s\n", g, dtg.string);
	free(g.string);


	g = getdata(k, &dtg);
	printf("%d %s\n", g, dtg.string);
	free(g.string);

	freekey(k);

	return 0;
}