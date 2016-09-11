#include "stdio.h"

int main(int argc, char * argv[])
{

	// printf("%s", fileChar);

	// MESSAGE msg;
	// memset(msg, 0, sizeof(MESSAGE));
	// msg.type = 15;
	char pth[12] = "/";
	// msg.u.m3.m3p1 = pth;
	// send_recv(3, 3, &msg);

	/* info */
	char info[1280];
	// info = (char*)msg.u.m3.m3p2;
	int ret = 1;
	ret = list(pth, info);
	printf("%d\n",ret);

	// int fd;
	// int n;
	// const char* filename = argv[1];
	// const char bufw[] = "imyourfather";
	// const int rd_bytes = 30;
	// char bufr[rd_bytes];

	/* create */
	// fd = open(filename, O_CREAT | O_RDWR);
	// printf("File created. fd: %d\n", fd);

	/* write */
	// n = write(fd, bufw, strlen(bufw));
	//assert(n == strlen(bufw));

	/* close */
	// close(fd);

	/* open */
	// fd = open(filename, O_RDWR);
	//assert(fd != -1);
	// printf("File opened. fd: %d\n", fd);

	/* read */
	// n = read(fd, bufr, rd_bytes);
	// bufr[n] = 0;
	// printf("%d bytes read: %s\n", n, bufr);

	
	// printf("233: %s\n", info);
	/* close */
	// close(fd);

}
