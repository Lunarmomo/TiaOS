#include "stdio.h"

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		printf("please input file name. :)\n");
	}
	char pth[13];
	pth[0] = '/';
	memcpy(pth+1, argv[1], 12);
	/* info */
	char dainfo[1280];
	int ret = 1;
	// printf("%s\n", argv[1]);
	// printf("%s\n", pth);
	ret = finfo(argv[1], dainfo);
	if (ret == 0)
	{
		printf("this file doesn't exists\n");
		return 0;
	}
	printf("%d\n",ret);
	printf("%s\n", dainfo);
}
