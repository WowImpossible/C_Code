#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//π/2 = 1+1/3+1/3*2/5+....
//上述公式输出满足精度要求的eps的π值。
//int main()
//{
//	double sum = 0.0;
//	int i = 0;
//	double temp = 1.0;
//	double eps = 0.0;
//	double temp1 = 0.0;

	//scanf("%lf", &eps);

	//for (i = 1; temp > eps; i++)
	//{
	//	sum += temp;
	//	temp1 = (double) i / (2 * i + 1);
	//	temp = temp * temp1;
//	}
//	printf("%lf\n", sum * 2);
//	return 0;
//}


//斐波那切数列，打印前20行，每行输出5个数(数组的方法)
int main()
{
	int arr[20] = { 1,1,0 };
	int i = 0;
	for (i = 2; i < 20; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	for (i = 0; i < 20; i++)
	{
		if ((i % 5 == 0)&&(i / 5 != 0))
			printf("\n");
		printf("%5d  ", arr[i]);
	}
	return 0;
}


//方法二：边求边打印斐波那切数列（Fibonacci）
//int main()
//{
//	int f;
//	int f1 = 1;
//	int f2 = 1;
//	int i = 3;
//	printf("%6d%6d", f1, f2);
//	for (; i <= 20; i++)
//	{
//		f = f1 + f2;
//		printf("%6d", f);
//		if (!(i % 5))
//			printf("\n");
//		f1 = f2;
//		f2 = f;
//	}
//	return 0;
//}