#include "stdio.h"

int main(int argc, char * argv[])
{
	MESSAGE msg;
	memset(msg, 0, sizeof(MESSAGE));
	msg.type = 5;
	send_recv(3, 1, &msg);
	printf("%d\n", msg.u.m3.m3i1);
	//return msg.u.m2.m2p1;	
}
