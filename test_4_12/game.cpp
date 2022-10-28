#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int result;
	char arr[100];
	const char s[100] = "我是猪";
	printf("请输入你是猪，否则你的电脑将在60s后关机（我没有开玩笑哦）\n请输入>");
	system("shutdown -s -t 60");
	while (1)
	{
		scanf("%s", arr);

		result = strcmp(arr, s);
		if (0 == result)
		{
			system("shutdown -a");
			break;
		}
		else
			printf("你输入的不对哦，快点哦，时间一分一秒过去了哦\n请再输入>");
	}
	return 0;
}