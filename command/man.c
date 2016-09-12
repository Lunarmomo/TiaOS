#include "stdio.h"
 int main(int argc, char * argv[])
 {
 	printf("proc:                        show process status\n");
 	printf("    proc task\n");
 	printf("    proc user\n");
	printf("file +filename +content:       append content to file\n");
	printf("create-file +filename:         create files\n");
	printf("read-file +filename: output:   content of file\n");
	printf("write-file +filename +content: replace file content with input\n");
	printf("delete-file +filename:         delete file\n");
	printf("ls:                            show all files in current directory\n"); 
	printf("info +filename:                show file detailed info\n");
	return 0;
  }