#include "stdio.h"

int main(int argc, char * argv[])
{
	int fd;
	if(argc <= 1)
	{
		printf("You should input file name. :)\n");
	}
	else
	{
		/* create */
		const char* filename = argv[1];
		fd = open(filename, O_CREAT | O_RDWR);
		if(fd == -1)
		{
			printf("File name existed, try another name. :)\n");
			return 0;
		}
		printf("File created, file name: %s,fd: %d\n", argv[1], fd);
		printf("you may modify you file by typing command: write-file filename content. :)\n");
	}
	
	/* close */
	close(fd);
}
