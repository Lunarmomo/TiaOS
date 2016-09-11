#include "stdio.h"

int main(int argc, char * argv[])
{
	char pth[12] = "/dev_tty1bochs";
	
	/* info */
	char dainfo[1280];
	int ret = 1;
	ret = list(pth, dainfo);
	printf("files listed below: \n");
	printf("%s\n", dainfo);
}
