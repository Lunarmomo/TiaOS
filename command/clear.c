#include "stdio.h"

//display imformation of process and tasks
int main(int argc, char * argv[])
{
	MESSAGE msg;
	memset(msg, 0, sizeof(MESSAGE));
	msg.type = 1006;
	send_recv(3, 1, &msg);
}
