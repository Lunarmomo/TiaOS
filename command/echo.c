#include "stdio.h"

int main(int argc, char * argv[])
{
	int i;
	if(argc == 1)
	{
		printf("echo hello");
		// return 0;
	}
	for (i = 1; i < argc; i++)
		printf("%s%s", i == 1 ? "" : " ", argv[i]);
	printf("\n");
	// return 0;
}
