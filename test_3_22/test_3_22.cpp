#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//求矩阵的转秩，即将一个矩阵的行和列互换
//int main()
//{
//	int arr1[3][2] = { {1,2},{3,4},{5,6} };
//	int arr2[2][3] = { 0 };
//	int i, j;
//
//	printf("before arr:\n");
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 2; j++)
//		{
//			printf("%2d  ", arr1[i][j]);
//			arr2[j][i] = arr1[i][j];
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("%2d  ", arr2[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//有一个3X4的矩阵，要求输出其中值最大的那个元素的值，以及所在的行号和列号
int main()
{
	int arr[3][4] = { {1,2,3,4},{9,8,7,6},{-10,10,-5,2} };
	int i = 0;
	int j = 0;
	int max = arr[0][0];
	int row = 0;
	int col = 0;
//如果使用预定义#define m 3  #define n 4的话，可以随时改变矩阵的行和列来比较，实用性更高
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
				row = i+1;
				col = j+1;
			}	
		}
	}
	printf("最大值为：%d\n行号为：%d\n列号为：%d\n", max, row, col);
	return 0;
}