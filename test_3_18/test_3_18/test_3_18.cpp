#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>


//�����ַ����ĳ���
int my_strlen(const char* p)//const���ε���*p��*p��ֵ���ܱ���
{
	assert(p != NULL);//assert���巶Χ
	int count = 0;
	while (*p++ != '\0')
		count++;
	return count;
}

//int main()
//{
//	//֮ǰû�и�arr��ʼ����ʱ�򣬳�����stack around the variable 'arr' was corrupted(��arr������ջ���ƻ�������Ϊû�����С�����²�������û������Ŀռ�)
//	char arr[100] = { 0 };
//	int ret = 0;
//	scanf("%s", arr);
//	ret = my_strlen(arr);
//	printf("strlen(arr) = %d\n", ret);
//	return 0;
//}
int main()
{
	char ret = '\0';
	printf("ret = %d\n", ret);
	return 0;
}