#include "stdio.h"

//display imformation of process and tasks
int main(int argc, char * argv[])
{
	MESSAGE msg;
	memset(msg, 0, sizeof(MESSAGE));
	msg.type = 3;
	send_recv(3, 1, &msg);
	printf("%d\n", msg.u.m3.m3i2);
	//return msg.u.m2.m2p1;	
}
