#include "stdio.h"

int main(int argc, char * argv[])
{
	// int fd;
	// int n;
	// const char filename[] = "blah";
	// const char bufw[] = "this is a file";
	// const int rd_bytes = 14;
	// char bufr[rd_bytes];


	// /* create */
	// fd = open(filename, O_CREAT | O_RDWR);
	// assert(fd != -1);
	// printf("File created. fd: %d\n", fd);

	// /* write */
	// n = write(fd, bufw, strlen(bufw));

	// /* close */
	// close(fd);

	// /* open */
	// fd = open(filename, O_RDWR);
	// printf("File opened. fd: %d\n", fd);
	
	// /* read */
	// n = read(fd, bufr, rd_bytes);
	// bufr[n] = 0;
	// printf("%d bytes read: %s\n", n, bufr);

	// /* close */
	// close(fd);


	int fd;
	int n;
	const char* filename = argv[1];
	const char bufw[] = "asdfgh";
	const int rd_bytes = 3;
	char bufr[rd_bytes];

	//assert(rd_bytes <= strlen(bufw));

	/* create */
	fd = open(filename, O_CREAT | O_RDWR);
	//assert(fd != -1);
	printf("File created. fd: %d\n", fd);

	/* write */
	n = write(fd, bufw, strlen(bufw));
	//assert(n == strlen(bufw));

	/* close */
	close(fd);

	/* open */
	fd = open(filename, O_RDWR);
	//assert(fd != -1);
	printf("File opened. fd: %d\n", fd);

	/* read */
	n = read(fd, bufr, rd_bytes);
	assert(n == rd_bytes);
	bufr[n] = 0;
	printf("%d bytes read: %s\n", n, bufr);

	/* close */
	close(fd);

}
