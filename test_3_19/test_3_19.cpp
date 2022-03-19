#define _CRT_SECURE_NO_WARNINGS 1

#include "my_strcpy.h"

int main()
{
	char arr1[] = "abcd";
	char arr2[] = "####";
	int length_arr1 = sizeof(arr1) / sizeof(arr1[0]);
	int length_arr2 = sizeof(arr2) / sizeof(arr2[0]);

	printf("%s\n", my_strcpy(arr2, arr1, length_arr2,length_arr1));//前面是目的的，后面是发源地

	return 0;
}