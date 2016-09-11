#include "stdio.h"

int main(int argc, char * argv[])
{
	char pth[12] = "/dev_tty1bochs";
	// msg.u.m3.m3p1 = pth;
	// send_recv(3, 3, &msg);

	/* info */
	char dainfo[1280];
	// info = (char*)msg.u.m3.m3p2;
	int ret = 1;
	ret = finfo(pth, dainfo);
	printf("%d\n",ret);
	printf("%s\n", dainfo);
}
