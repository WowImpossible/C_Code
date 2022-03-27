#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu {
	char name[20];
	int age;
	double grad;
	char xuhao[20];
}stu;


//整形打印
void print_int(int* p, int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%5d", p[i]);
	}
}


//浮点型打印
void print_float(float* p, int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%f  ", p[i]);
	}
}


//结构体打印
void print_stu(stu* p, int sz)
{
	int i;
	for(i = 0;i<sz;i++)
		printf("%-9s\t%-9d\t%-9lf\t%-9s\n", (p[i]).name,(p[i]).age,(p[i]).grad,(p[i]).xuhao);
}


//整形比较法
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *((int*)e2));
}

//浮点型比较法
int cmp_float(const void* e1, const void* e2)
{
	return ((int)(*(float*)e1 - *(float*)e2));
}


//结构体比较
int cmp_stu_name(const void* e1, const void* e2)
{
	return strcmp(((stu*)e1)->name,((stu*)e2)->name);//->的优先级比强制类型转换的类型高，所以要用括号括起来
}

int cmp_stu_age(const void* e1, const void* e2)
{
	return (((stu*)e1)->age-((stu*)e2)->age);
}

int cmp_stu_grade(const void* e1, const void* e2)
{
	return ((int)(((stu*)e1)->grad-((stu*)e2)->grad));//->的优先级比强制类型转换的类型高，所以要用括号括起来
}

int cmp_stu_xuehao(const void* e1, const void* e2)
{
	return strcmp(((stu*)e1)->xuhao, ((stu*)e2)->xuhao);//->的优先级比强制类型转换的类型高，所以要用括号括起来
}

//功能：交换两个数
//注意这里传进去的是字符指针。同时还需要传进元素的字节数，因为char*一次只能
//改变一个字节，只有知道元素一共有多少字节数时才知道要改变多少个字节（重要的处理方法）
void Swap(char* p1,char* p2,int width)
{
	int i = 0;
	char temp;
	//循环用来逐字节改变元素
	for (i = 0; i < width; i++)
	{
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		//要记得地址++，要不然改不了
		p1++;
		p2++;
	}
}


//功能：比较两个数（按从小到大的顺序）
void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{
	//趟数
	int i = 0;
	int j = 0;
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		//两两比较的次数
		for (j = 0; j < sz - 1 - i; j++)
		{
			//点睛之笔：强制类型转换与此同时要记得将字节数传进来。
			//要注意，这里要求数组的下标自己变，所以j * width和(j+1) * width的作用就出现了
			if (cmp((char*)base + j * width, (char*)base + (j+1) * width) > 0)
			{
				Swap((char*)base+j*width, (char*)base + (j+1) * width,width);
			}
		}
	}
	
}


//使用qsort实现快速排序(一半自己写，一半原来就有的)，可以排各种各样类型的顺序
//int main()
//{
//	int arr[] = { 7,9,8,6,5,4,3,2,1,0 };
//	float f[] = { 8.0,9.0,6.0,7.0,1.0,2.0,3.0,4.0,5.0,0.0 };
//	int sza = sizeof(arr) / sizeof(arr[0]);
//	int szf = sizeof(f) / sizeof(f[0]);
//
//	qsort(arr, sza, sizeof(arr[0]), cmp_int);
//	qsort(f, szf, sizeof(f[0]), cmp_float);
//
//	print1(arr,sza);
//	printf("\n");
//	print2(f,szf);
//
//	return 0;
//}



//全部自己写，bubble_sort(void* base,int sz,int width,int(*cmp)(const void* e1 ,const void* e2))
int main()
{
	int arr[] = { 7,9,8,6,5,4,3,2,1,0 };
	float f[] = { 8.0,9.0,6.0,7.0,1.0,2.0,3.0,4.0,5.0,0.0 };
	stu s[3] = { { "zhangsan",18,98.9,"211218092"},{"lisi",19,78.6,"211218090"},{"wangwu",20,89.6,"211218099"}};
	int szs = sizeof(s) / sizeof(s[0]);
	int sza = sizeof(arr) / sizeof(arr[0]);
	int szf = sizeof(f) / sizeof(f[0]);

	bubble_sort(arr, sza, sizeof(arr[0]), cmp_int);
	bubble_sort(f, szf, sizeof(f[0]), cmp_float);
	bubble_sort(s, szs, sizeof(s[0]), cmp_stu_xuehao);
	print_int(arr,sza);
	printf("\n");
	print_float(f, szf);
	printf("\n");
	print_stu(s, szs);
}

