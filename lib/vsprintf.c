
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                              vsprintf.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "keyboard.h"
#include "proto.h"



/*======================================================================*
                                i2a
 *======================================================================*/
PRIVATE char* i2a(int val, int base, char ** ps)
{
	int m = val % base;
	int q = val / base;
	if (q) {
		i2a(q, base, ps);
	}
	*(*ps)++ = (m < 10) ? (m + '0') : (m - 10 + 'A');

	return *ps;
}


// /*======================================================================*
//                                 vsprintf
//  *======================================================================*/
// /*
//  *  为更好地理解此函数的原理，可参考 printf 的注释部分。
//  */
// PUBLIC int vsprintf(char *buf, const char *fmt, va_list args)
// {
// 	char*	p;

// 	va_list	p_next_arg = args;
// 	int	m;

// 	char	inner_buf[STR_DEFAULT_LEN];
// 	char	cs;
// 	int	align_nr;

// 	for (p=buf;*fmt;fmt++) {
// 		if (*fmt != '%') {
// 			*p++ = *fmt;
// 			continue;
// 		}
// 		else {		/* a format string begins */
// 			align_nr = 0;
// 		}

// 		fmt++;

// 		if (*fmt == '%') {
// 			*p++ = *fmt;
// 			continue;
// 		}
// 		else if (*fmt == '0') {
// 			cs = '0';
// 			fmt++;
// 		}
// 		else {
// 			cs = ' ';
// 		}
// 		while (((unsigned char)(*fmt) >= '0') && ((unsigned char)(*fmt) <= '9')) {
// 			align_nr *= 10;
// 			align_nr += *fmt - '0';
// 			fmt++;
// 		}

// 		char * q = inner_buf;
// 		memset(q, 0, sizeof(inner_buf));

// 		switch (*fmt) {
// 		case 'c':
// 			*q++ = *((char*)p_next_arg);
// 			p_next_arg += 4;
// 			break;
// 		case 'x':
// 			m = *((int*)p_next_arg);
// 			i2a(m, 16, &q);
// 			p_next_arg += 4;
// 			break;
// 		case 'd':
// 			m = *((int*)p_next_arg);
// 			if (m < 0) {
// 				m = m * (-1);
// 				*q++ = '-';
// 			}
// 			i2a(m, 10, &q);
// 			p_next_arg += 4;
// 			break;
// 		case 's':
// 			strcpy(q, (*((char**)p_next_arg)));
// 			q += strlen(*((char**)p_next_arg));
// 			p_next_arg += 4;
// 			break;
// 		default:
// 			break;
// 		}

// 		int k;
// 		for (k = 0; k < ((align_nr > strlen(inner_buf)) ? (align_nr - strlen(inner_buf)) : 0); k++) {
// 			*p++ = cs;
// 		}
// 		q = inner_buf;
// 		while (*q) {
// 			*p++ = *q++;
// 		}
// 	}

// 	*p = 0;

// 	return (p - buf);
// }



/*
 *  为更好地理解此函数的原理，可参考 printf 的注释部分。
 */



int __res = 0;

#define do_div(n,base)  (\
	__res=((unsigned long)n)%(unsigned)base,\
	n=((unsigned long)n)/(unsigned)base,\
	__res\
	)

int is_digit(int c)
{
	if (c <=9 && c >= 0) return 1;
	else return 0;
}

typedef char *va_list;
#define va_round_size(TYPE) (((sizeof(TYPE)+sizeof(int)-1)/sizeof(int))*sizeof(int))    //4的整数倍
#define va_start(AP,LASTARG) (AP=((char *)&(LASTARG)+va_round_size(LASTARG)))
#define va_arg(AP,TYPE) (AP+=va_round_size(TYPE),*((TYPE*)(AP-va_round_size(TYPE))))    //得到可变参数的地址，第一次返回时得到第一个参数的地址
#define va_end(AP)		//将释放参数表AP

#define ZEROPAD 1
#define PLUS 4
#define SPACE 8   //??
#define LEFT 16
#define SPECIAL 32  //??
#define SMALL 64
#define SIGN  2

static int skip_atoi(const char **s)
{
 int i=0;

 while (is_digit(**s))
  i = i*10 + *((*s)++) - '0';
 return i;
}

static char *number(char *str,int num,int base,int size,int precision,int type)
 {
     char c,sign,tmp[36];
     const char *digits="0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ";
     int i;
     if(type&SMALL) digits="0123456789abcdefghijklmnopqrstuvwxyz";
     if(type&LEFT) type&=~ZEROPAD;
     if(base<2||base>36)
         return 0;
     c=(type&ZEROPAD)?'0':' ';

     if(type&SIGN&&num<0){
         sign='-';
         num=-num;
     }
     else
         sign=(type&PLUS)?'+':((type&SPACE)?' ':0);

     if(sign)
         size--;

     if(type&SPECIAL)
         if(type==16)
             size-=2;
         else if(base==8)
             size--;

     i=0;
     if(num==0)
         tmp[i++]='0';
     else 
         while(num!=0)
             tmp[i++]=digits[do_div(num,base)];
     if(i>precision)
         precision=i;
     size=-precision;

     if(!(type&(ZEROPAD+LEFT)))
         while(size-->0)
             *str++=' ';
     if(sign)
         *str++=sign;
     if(type&SPECIAL)
         if(base==8)
             *str++='0';
         else if(base == 16)
         {
             *str++='o';
             *str++=digits[33];
         }

     if(!(type&LEFT))
         while(size-->0)
             *str++=c;
     while(i<precision--)
         *str++='0';
     while(i-->0)
         *str++=tmp[i];
     while(size-->0)
         *str++=' ';

     return str;
 }

int vsprintf(char *buf, const char *fmt, va_list args)
 	{
 	    int len;
 	    int i;
 	    char *str;
 	    char *s;
 	    int *ip;
 	 
 	    int flags;
 	 
 	    int field_width;   //输出大小
 	    int precision;        /* min. # of digits for integers; max number of chars for from string */
 	    int qualifier;        /* 'l' for integer fields */
 	 
 	    for (str=buf; *fmt; ++fmt) 
	    {    //str为最终存放字符串的位置但是他随着字符串增长而增长，buf始终指向最终字符串的启始位置。fmt为格式字符串
 	        if (*fmt != '%') 
			{                        
 	            *str++ = *fmt;  //如果不是%则直接复制
 	            continue;
 	        } 	           
 	        flags = 0;

 	        while(1)
 	        {
 	            ++fmt;      //先自增，为跳过第一个%,fmt指向%后一位
 	            if (*fmt == '-') 
 	                flags |= LEFT;   //左对齐
 	            else if (*fmt == '+')
 	                flags |= PLUS;	//带符号输出
 	            else if (*fmt == ' ')
 	                flags |= SPACE; //判断标志位，并设置flags
 	            else if (*fmt == '#')
 	                flags |= SPECIAL; //带有标志的整数
 	            else if (*fmt == '0')
 	                flags |= ZEROPAD; //补0
 	            else break;
 	        }
 	        /* get field width */
 	        field_width = -1;
 	        if (is_digit(*fmt))
 	            field_width = skip_atoi(&fmt);
 	        else if (*fmt == '*') {
 	            /* it's the next argument */
 	            field_width = va_arg(args, int);
 	            if (field_width < 0) {
 	                field_width = -field_width;
 	                flags |= LEFT;
 	            }
 	        }
 	 
 	        /* get the precision */
 	        precision = -1;
 	        if (*fmt == '.') {
 	            ++fmt;   
 	            if (is_digit(*fmt))
 	                precision = skip_atoi(&fmt);
 	            else if (*fmt == '*') {
 	                /* it's the next argument */
 	                precision = va_arg(args, int);
 	            }
 	            if (precision < 0)
 	                precision = 0;
 	        }
 	 
 	        /* get the conversion qualifier */
 	        qualifier = -1;
 	        if (*fmt == 'l') {  //输出长型数
 	            qualifier = *fmt;
 	            ++fmt;
 	        } 

 	        switch (*fmt) {
 	        case 'c':
 	            if (!(flags & LEFT))
 	                while (--field_width > 0)
 	                    *str++ = ' ';
 	            *str++ = (unsigned char) va_arg(args, int);
 	            while (--field_width > 0)
 	                *str++ = ' ';
 	            break;	 
 	        case 's':  //字符串
 	            s = va_arg(args, char *);
 	            len = strlen(s);
 	            if (precision < 0)
 	                precision = len;
 	            else if (len > precision)
 	                len = precision;
 	 
 	            if (!(flags & LEFT))
 	                while (len < field_width--)
 	                    *str++ = ' ';
 	            for (i = 0; i < len; ++i)
 	                *str++ = *s++;
 	            while (len < field_width--)
 	                *str++ = ' ';
 	            break;	 
 	        case 'o':   //无符号以八进制表示的整数
 	            str = number(str, va_arg(args, unsigned long), 8,
 	                field_width, precision, flags);
 	            break;	 
 	        case 'p':  //指针的值
 	            if (field_width == -1) {
 	                field_width = 8;
 	                flags |= ZEROPAD;
 	            }
 	            str = number(str,
 	                (unsigned long) va_arg(args, void *), 16,
 	                field_width, precision, flags);
 	            break; 	 
 	        case 'x':
 	            flags |= SMALL;
 	        case 'X':
 	            str = number(str, va_arg(args, unsigned long), 16,
 	                field_width, precision, flags);
 	            break;
        	case 'd':
			case 'i':
 	            flags |= SIGN;
 	        case 'u':  //十进制无符号整数
 	            str = number(str, va_arg(args, unsigned long), 10,
 	                field_width, precision, flags);
 	            break;	 
 	        case 'n':
 	            ip = va_arg(args, int *);
 	            *ip = (str - buf);
 	            break;
 	        default:
 	            if (*fmt != '%')
       				*str++ = '%';
 	            if (*fmt)
 	                *str++ = *fmt;//如果格式转换符不正确则输出%+不正确的格式转换符。如果是%%，则只输出一个%
 	            else
 	                --fmt;//如果转换格式符不是上面这些正确的，也不是空，那么直接输出；否则就指向末尾了，fmt后退一位，这样在for循环自动再加1进行判断时*fmt的条件就不满足，退出for循环
 	            break;
 	        }
 	    }
 	    *str = '\0';
 	    return str-buf;
}


/*======================================================================*
                                 sprintf
 *======================================================================*/
int sprintf(char *buf, const char *fmt, ...)
{
	va_list arg = (va_list)((char*)(&fmt) + 4);        /* 4 是参数 fmt 所占堆栈中的大小 */
	return vsprintf(buf, fmt, arg);
}
