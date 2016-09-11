#include "stdio.h"

int main(int argc, char * argv[])
{
	int fd, n;
	int content_length = 0;
	if(argc <= 2)
	{
		printf("You should input file name and content to be written in. :)\n");
		return 0;
	}
	const char* filename = argv[1];
	fd = open(filename, O_RDWR);
	if(fd == -1)
	{
		printf("no file with this name found. :(\n");
		return 0;
	}
	const char* content = argv[2];
	content_length = strlen(content);
	n = write(fd, content, content_length);
	printf("%d\n", n);
	close(fd);
	if(n == content_length)
	{
		printf("write success\n");
	}
	return 0;
}
