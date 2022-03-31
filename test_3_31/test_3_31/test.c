#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>


//单纯的测试空格和\0的区别，空格的ASCII码和空格的ASCII是不一样的，所以算长度的时候空格也是
//#include <string.h>
//
//int main()
//{ 
//	char s[] = "Address  ";
//	char ch = '\0';
//	printf("%d\n", strlen(s));
//	printf("%d", ch);
//	return 0;
//}


//将s串中出现的s1串全部替换成s2里面的字符串
int my_rep(char* s, char* s1, char* s2)
{
	assert(s && s1 && s2);
	assert(strlen(s1) == strlen(s2));
	char* p = NULL;//用来遍历s里面所有的元素
	char* p1 = NULL;//用来遍历s1里面所有的元素
	char* p2 = s2;//用来遍历s1里面所有的元素
	char* cur = s;//用来定位此时的地址
/*	int flag_num = 0*/;//确定要替换的字符串长度,也可以用sizeof
	int isflag = 0;//判断是否找到字符串且可以替换多处
	int flag_pri = 0;//判断是否找到过字符串
	int i = 0;//用来将s2的字符串用循环的方式传到s中
	int sz = strlen(s1);
	while (*cur)
	{
		p = cur;
		p1 = s1;
		while (*p1 && *p && (*p == *p1))
		{
			p++;
			p1++;
			//flag_num++;
		}
		if (!*p1)
		{ 
			isflag = 1;
			flag_pri = 1;
			for (i = 0; i < sz; i++)//如果用flag_num的话，要写成flag_num；
			{
				*(cur + i) = *(p2 + i);
			}
			p2 = s2;
		}
		if (!(*p) && (*p1)) return 0;
		if (isflag) cur += sz;//如果要用flag_num的话，要改成flag_num-1
		cur++;
		isflag = 0;
		//flag_num = 0;要记得归零
	}
	if (!flag_pri)
		return 0;
	else
		return 1;
}

int main()
{
	char s[] = "abbbcabbbc";
	char s1[20];
	char s2[20];

	printf("原来的s:%s\n", s);
	printf("请输入要替换的字符串:");
	gets(s1);
	printf("s1:%s\n", s1);
	printf("请输入要替换成的字符串:");
	gets(s2);
	printf("s2:%s\n", s2);

	printf("\n");

	//my_rep(s, s1, s2);

	if (my_rep(s, s1, s2))
	{
		printf("改变后的s:%s", s);
	}
	else
		printf("没有找到对应的字符串");

	return 0;
}