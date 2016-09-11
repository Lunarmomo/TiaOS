#include "stdio.h"


//display imformation of process and tasks
int main(int argc, char * argv[])
{
	MESSAGE msg;
	memset(msg, 0, sizeof(MESSAGE));
	msg.type = 5;
	send_recv(3, 1, &msg);

	if (argc == 1)
	{
		print_user_proc(&msg);
		printf("\n");
		print_task(&msg);

	}
	else if (argc == 2)
	{
		if(argv[1][0] == 't')
			print_task(&msg);
		else if(argv[1][0] == 'u')
			print_user_proc(&msg);
		else
			{
				printf("bad command\n");
				printf("%c\n", argv[1][2]);
			}
	}
	else
	{
		printf("you can try proc-status, proc-status task or proc-status user. :)\n");
	}
}


void print_user_proc(MESSAGE* msg)
{
	MESSAGE message = *msg;
	char* name;
	int stack_size = 0;
	int e_address = 0;
	printf("user process list:\npid\tname\tstack size\tentry address\n");
	for(int i= 0; i < message.u.m3.m3i1; i++)
	{
		name = (char*)(message.u.m3.m3p1+(i+1)*2*sizeof(int)+i*sizeof(char[32]));
		stack_size = *(int*)(message.u.m3.m3p1+sizeof(int)*(i*2+1)+i*sizeof(char[32]));
		e_address = *(int*)(message.u.m3.m3p1+sizeof(int)*(i*2)+i*sizeof(char[32]));
		printf("%d\t  ", i);
		printf("%s\t", name);
		printf("%d\t\t", stack_size);
		printf("%d\n", e_address);
	}
}

void print_task(MESSAGE* msg)
{
	MESSAGE message = *msg;
	char* name;
	int stack_size = 0;
	int e_address = 0;
	printf("task list:\npid\tname\tstack size\tentry address\n");
	for(int i= 0; i < message.u.m3.m3i2; i++)
	{
		name = (char*)(message.u.m3.m3p2+(i+1)*2*sizeof(int)+i*sizeof(char[32]));
		stack_size = *(int*)(message.u.m3.m3p2+sizeof(int)*(i*2+1)+i*sizeof(char[32]));
		e_address = *(int*)(message.u.m3.m3p2+sizeof(int)*(i*2)+i*sizeof(char[32]));
		printf("%d\t  ", i);
		printf("%s\t", name);
		printf("%d\t\t", stack_size);
		printf("%d\n", e_address);
	}
}