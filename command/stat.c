#include "stdio.h"

int main(int argc, char * argv[])
{
	char pth[13];
	pth[0] = '/';
	memcpy(pth+1, argv[1], 12);
	/* info */
	char dainfo[1280];
	int ret = 1;
	// printf("%s\n", argv[1]);
	// printf("%s\n", pth);
	ret = finfo(argv[1], dainfo);
	printf("%d\n",ret);
	printf("%s\n", dainfo);
}
