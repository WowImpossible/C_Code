#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int result;
	char arr[100];
	const char s[100] = "������";
	printf("������������������ĵ��Խ���60s��ػ�����û�п���ЦŶ��\n������>");
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
			printf("������Ĳ���Ŷ�����Ŷ��ʱ��һ��һ���ȥ��Ŷ\n��������>");
	}
	return 0;
}