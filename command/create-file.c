#include "stdio.h"

int main(int argc, char * argv[])
{
	int fd;
	int n;
	
	const char bufw[] = "abcde";
	const int rd_bytes = 5;
	char bufr[rd_bytes];
	if(argc <= 1)
	{
		printf("You should input file name. :)\n");
	}
	else
	{
		printf("%s", argv[1]);
		/* create */
		const char* filename = argv[1];
		fd = open(filename, O_CREAT | O_RDWR);
		if(fd == -1)
		{
			printf("File name existed, try another name. :)\n");
			return 0;
		}
		printf("File created. name: %s,fd: %d\n", argv[1], fd);
	}
	
	/* close */
	close(fd);
}
