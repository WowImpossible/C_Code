#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>


//计算字符串的长度
int my_strlen(const char* p)//const修饰的是*p，*p的值不能变了
{
	assert(p != NULL);//assert定义范围
	int count = 0;
	while (*p++ != '\0')
		count++;
	return count;
}

int main()
{
	//之前没有给arr初始化的时候，出现了stack around the variable 'arr' was corrupted(即arr附近的栈被破坏，是因为没定义大小，导致操作到了没有申请的空间)
	char arr[100] = { 0 };
	int ret = 0;
	scanf("%s", arr);
	ret = my_strlen(arr);
	printf("strlen(arr) = %d\n", ret);
	return 0;
}