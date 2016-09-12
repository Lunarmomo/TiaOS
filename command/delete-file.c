#include "stdio.h"

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		printf("please input file name. :)\n");
		return 0;
	}
	int fd = open(argv[1], O_RDWR);
	if(fd == -1)
	{
		printf("can not find file\n");
		return 0;
	}
	close(fd);
	const char* filename = argv[1];
	unlink("asd");
	return 0;
}
