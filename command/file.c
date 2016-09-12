#include "stdio.h"

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		printf("input file name and content to append. :)\n");
		return 0;
	}
	int fd;
	char* temp;
	const int rdcnt = 1024;
	const char* filename = argv[1];
	
	char* content;
	int content_length;
	fd = open(filename, O_RDWR);
	int n;
	if (fd == -1)
	{
		printf("file not found\n");
		return 0;
	}
	for (int i = 2; i < argc; i++)
	{
		content = argv[i];
		content_length = strlen(content);
		content[content_length] = ' ';
		content_length++;
		// if(i+1 == argc)
		// {
		// 	content[content_length] = '\n';
		// 	content_length++;
		// }
		fd = open(filename, O_RDWR);
		n =  read(fd, temp, rdcnt);
		printf("n: %d  ", n);
		printf("content_length: %d\n", content_length);
		lseek(fd, n, 1);
		write(fd, content, content_length);
	}
	close(fd);
	return 0;
}