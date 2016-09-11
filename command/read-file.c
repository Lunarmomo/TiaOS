#include "stdio.h"

int main(int argc, char * argv[])
{
	int atoi (char* s);
	int fd, n;
	const char* content;
	if(argc < 2)
	{
		printf("You should input the file name, and you can choose how many characters you wanna read.\n");
		return 0;
	}
	const int rd_count = argc == 3 ? atoi(argv[2]) : 1024;
	const char* filename = argv[1];
	fd = open(filename, O_RDWR);
	if(fd == -1)
	{
		printf("no file with this name found\n");
		return 0;
	}
	n = read(fd, content, rd_count);
	close(fd);
	if (n == 0)
	{
		printf("this file is now empty, try write-file filenema content. :)\n");
	}
	else if (n <= rd_count)
	{
		printf("read success, %dcharacters read,content:\n", n);
		printf("%s\n", content);
	}
	else
	{
		printf("error\n");
	}
	return 0;
}

char * itoa(char * str, int num)/* 数字前面的 0 不被显示出来, 比如 0000B800 被显示成 B800 */
{
	char *	p = str;
	char	ch;
	int	i;
	int	flag = 0;

	*p++ = '0';
	*p++ = 'x';

	if(num == 0){
		*p++ = '0';
	}
	else{	
		for(i=28;i>=0;i-=4){
			ch = (num >> i) & 0xF;
			if(flag || (ch > 0)){
				flag = 1;
				ch += '0';
				if(ch > '9'){
					ch += 7;
				}
				*p++ = ch;
			}
		}
	}

	*p = 0;

	return str;
}

int atoi(char *str)  
{  
        
        int bMinus = 0;  
        int result = 0;  
  
        if(('0'>*str || *str>'9')&&(*str=='+'||*str=='-'))  
        {  
               if(*str=='-')  
                bMinus = 1;  
               *str++;  
        }  
        while( *str != '\0')  
        {  
                if('0'> *str || *str>'9')  
                        break;  
                else  
                        result = result*10+(*str++ - '0');  
        }  
  
        if (*str != '\0')//no-normal end  
                return -2;  
  
        return bMinus?-result:result;  
}  