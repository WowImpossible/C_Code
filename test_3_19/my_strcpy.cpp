#define _CRT_SECURE_NO_WARNINGS 1

#include "my_strcpy.h"


//这个函数是用来字符串拷贝的（包括‘\0’），返回类型是要拷贝到的地方的地址，
// 即目的地的地址，其中pa是目的的地址的指针，pb是源地址，length1是目的地的字节大小，
//length2是起源地的字节大小。
char* my_strcpy(char* pa, const char* pb,int length1,int length2)
{
	char* ret = pa;    //用来接收目的的的地址，后面随着++的进行，pa的地址将不是首元素地址
	assert(pa != NULL);//用来判断目的的不是空指针，当括号里面的条件为真，无反应，为假报错
	assert(pb != NULL);
	assert(length1 >= length2);
	while (*pa++ = *pb++);
	return ret;
}