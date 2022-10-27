#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int count(char* str, char* substr)
{
	int i, j, k;
	int num = 0;
	for (i = 0; str[i] != '\0';i++)
	{
		for (j = i, k = 0; substr[k] == str[j]; k++,j++)
		{
			if (substr[k + 1] == '\0')
			{
				num++;
				break;
			}
		}
	}
	return num;
}


int main()
{
	char str[] = "abcdefgabcdefgabcdefgabcdefg";
	char substr[] = "abcd";
	int num1 = 0;
	num1 = count(str, substr);
	printf("num1 = %d\n", num1);
	return 0;
}