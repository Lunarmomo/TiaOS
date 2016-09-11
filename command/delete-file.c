#include "stdio.h"

int main(int argc, char * argv[])
{
	int fd;
	if (argc < 2)
	{
		printf("please input the file name. :)\n");
		return 0;
	}
	fd = open(argv[1], O_RDWR);
	if(fd == -1)
	{
		printf("this file doesn't exist. :)\n");
		close(fd);
		return 0;
	}
	char temp[20];
	temp[0] = '/';
	for(int i = 1; *argv[1] ; i++, argv[1]++)
	{
		temp[i] = *argv[1];
	}
	const char* pathname = temp;
	printf("%s\n", pathname);
	// int status = unlink(pathname);
	// if(status == 0)
	// {
	// 	printf("success\n");
	// }
	// else if (status == -1)
	// {
	// 	printf("fail\n");
	// }
	return 0;
}
