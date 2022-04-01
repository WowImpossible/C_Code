#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//#include <string.h>
//
//////设计一个程序，从键盘上输入文本文件名，分别统计该文件所包含的英文字母（不区分大小写）
//////数字字符和其他字符的个数（文件名是nihao.txt）
//int main()
//{
//	char ch;
//	char s[] = "xxxxxxxxxx.xxxxx";
//	int letter = 0;
//	int dig = 0;
//	int other = 0;
//	gets(s);
//	//打开文件
//	FILE* fp = fopen((const char*)s, "r");//fopen的参数类型是const char*的
//	if (!fp)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	ch = fgetc(fp);
//	//读取文件内容
//	while (ch != EOF)
//	{
//		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
//			letter++;
//		else if (ch >= '0' && ch <= '9')
//			dig++;
//		else
//			other++;
//		ch = fgetc(fp);
//	}
//	fclose(fp);
//	fp = NULL;
//
//	printf("letter=%d\n", letter);
//	printf("dig=%d\n", dig);
//	printf("other=%d\n", other);
//
//	return 0;
//}


//打印乘法表
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int a[10] = { 0 };
//	printf("*");
//	for (i = 1; i < 10; i++)
//	{
//		a[i] = i;
//		printf("%4d", a[i]);
//	}
//	printf("\n");
//
//	for (i = 1; i < 10; i++)
//	{
//		printf("%d", i);
//		for (j = 1; j <= i; j++)
//		{
//			printf("%4d", i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

int main()
{
	char s[81];
	int i = 0;
	//gets(s);
	//while ((s[i++] = getchar()) != '\n');
	//s[i] = '\0';
	scanf("%s", s);
	//do
	//{
	//	scanf("%c", &s[i]);
	//} while (s[i++] != '\n');
	//s[i] = '\0';
	printf("%s", s);
	return 0;
}
