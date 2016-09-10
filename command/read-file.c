#include "stdio.h"

int main(int argc, char * argv[])
{
	if(argc == 0)
	{
		printf("You should input the name of file\n");
	}
	else
	{
		printf("filename: %s\n", argv[1]);
	}
}
