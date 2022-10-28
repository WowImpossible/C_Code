//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <string.h>
//
//
////删除字符串s里面中所出现的与变量c相同的字符
//char* squeeze(char* s, char* ch,int num)
//{
//	int i = 0;
//	int j = 0;
//	//char arr[100] = { 0 };//同时也可以不需要借助第二个数组，可以放在一个数组里面减小内存的消耗
//	for (i = 0; s[i] != '\0';i++)
//	{
//		if (s[i] != (*ch))
//		{
//			s[j++] = s[i];
//		}
//	}
//	s[j] = '\0';
//	//strcpy(s, arr);//使用这一步的原因是，局部变量出了函数内部就会被销毁
//	return s;//返回首元素的地址
//}
//
//
//int main()
//{
//	char s[1000] = "abcdefg";
//	char c = 'c';
//	char* p = NULL;
//	int num;
//
//	num = sizeof(s) / sizeof(s[0]);
//	p = squeeze(s, &c,num);
//	printf("result is %s", p);
//
//	return 0;
//}

#include<stdio.h>


int main()
{
	return 0;
}
