#include "stdio.h"

//display imformation of process and tasks
int main(int argc, char * argv[])
{
	MESSAGE msg;
	memset(msg, 0, sizeof(MESSAGE));
	msg.type = 5;
	send_recv(3, 1, &msg);
	printf("%s\n", (char*)(msg.u.m3.m3i1+sizeof(int)*4)+sizeof(char[32]));
	//return msg.u.m2.m2p1;	
}
