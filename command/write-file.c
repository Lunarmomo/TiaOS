#include "stdio.h"

int main(int argc, char * argv[])
{
	// if(argc == 0)
	// {
	// 	printf("You should input the name of file\n");
	// }
	// else
	// {
	// 	printf("filename: %s\n", argv[1]);
	// }
	int i;
	for (i = 1; i < argc; i++)
		printf("%s%s", i == 1 ? "" : " ", argv[i]);
	printf("\n");

	return 0;
}
