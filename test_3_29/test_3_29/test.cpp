#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//学会使用strstr库函数（在一个字符串里面找一个子字符串,返回值是指针，即找到字符串的地址）
//int main()
//{
//	char* ret = NULL;
//	char arr1[] = "abcdefghi";
//	char arr2[] = "cdef";
//
//	ret = strstr(arr1, arr2);
//	printf("%s\n", ret);
//
//	return 0;
//}

//自己写一个my_strstr函数来实现其相应的功能
//当你要使一个数具有记忆功能时，可以使用while循环来写
//即：temp = p1，但是p1的值一直在变，而你不希望它一直变，你希望它停在某个条件下时
//要特别注意从abbbcdefg中找bbc这个子串的特例
char* my_strstr(const char* p1,const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 = NULL;//用来遍历p1里面所有的元素，这样p1的值就不用变了
	char* s2 = NULL;//用来遍历p2里面所有的元素，这样p2的值就不用变了
	//强制类型转换的原因：p2是const char*，他是受保护的，cur是不受保护的
	//cur的作用是固定在字符串里面找到子串时的地址，针对上面那个特例
	char* cur = (char*)p1;
	if (!*p2) return (char*)p1;
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0') return cur;
		if (*s1 == '\0') return NULL;
		cur++;
	}
	return NULL;
}


int main()
{
	char* ret = NULL;
	char arr1[] = "abbbcdefghi";
	char arr2[] = "bbc";

	ret = my_strstr(arr1, arr2);
	printf("%s\n", ret);

	return 0;
}