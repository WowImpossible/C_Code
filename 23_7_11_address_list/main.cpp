#define _CRT_SECURE_NO_WARNINGS 1
#include "contract.h"
//通讯录的最大容量
#define MAX_Space 100

//1、该项目的作用：通讯录。记录一些联系人的信息。
//2、没有考虑到的地方：1、没有考虑到，如果放满了的话，没有提示一下。
	  //2、没有考虑到有重名的情况。(这个解决起来还是挺简单的，只需要将找的放在另外一个数组里面，在显示那个数组里的元素)
     //3、使用的是一个全局变量来记录通讯录的人数，不太好，因为全局变量是大家都可以改变的，可以考虑用结构体试试。
//3、按照名字来排序这个还没有想好要怎么写。(strcmp来进行排序)


//显示通讯录的人数，以及随时调整数组的地址。
int num = 0;

//查找的名字是否在通讯录里面,在返回下标，不在返回-1
int check = -2;

int main(void)
{
	char input = 0;
	//选择删除的方式
	int del_choose = 0;
	peoinfo peonum[MAX_Space] = {0};
	do
	{
		//打印菜单
		menu();
		printf("请选择要执行的操作 > ");
		scanf("%c", &input);
		//开始执行操作
		switch (input)
		{
		//add
		case '1':
			//清除缓冲区。因为scanf在输入%c类型时\n也会留在缓存区，把字符取走后，\n就会被读到。所以使用getchar把换行符拿走。
            //但是%s %d %f 使用scanf读取时不会把\n留在缓冲区。
			if (getchar() == '\n')
			{
				Add_peoinfo(peonum);
				getchar();
			}
			else
			{
				//直到把缓存区里面的数据全部取走，包括\n
				while (getchar() != '\n');
				printf("error：不存在该选项\n");
			}
			break;
		//delete
		case '2':
			if (getchar() == '\n')
			{
				if (Check_peoinfo())
				{
					printf("请输入想要删除的方式：1、按照序号删除   2、按照名字删除:>");
					scanf("%c", &del_choose);
					switch (del_choose)
					{
					case '1':
						getchar();
						Delete_peoinfo_by_num(peonum);
						break;
					case '2':
						getchar();
						Delete_peoinfo_by_name(peonum);
						break;
					default:
						getchar();
						printf("选择错误\n");
						break;
					}
				}
				else
				{
					printf("此为空的通讯，没有删除的必要\n");
				}
			}
			else
			{
				while (getchar() != '\n');
				printf("error：不存在该选项\n");
			}
			break;
		//search
		case '3':
			if (getchar() == '\n')
			{
				printf("请输入要查询联系人名字:>");
				Search_peoinfo(peonum);
			}
			else
			{
				while (getchar() != '\n');
				printf("error：不存在该选项\n");
			}
			break;
		//modify
		case '4':
			if (getchar() == '\n')
			{
				printf("请输入要修改的联系人名字:>");
				Modify_peoinfo(peonum);
			}
			else
			{
				while (getchar() != '\n');
				printf("error：不存在该选项\n");
			}
			break;
			//Modify_peoinfo(peonum);
		//show
		case '5':
			if (getchar() == '\n')
			{
				Show_peoinfo(peonum);
			}
			else
			{
				while (getchar() != '\n');
				printf("error：不存在该选项\n");
			}
			break;
		//sort
		case '6':
			if (getchar() == '\n')
			{
				Sort_peoinfo(peonum);
			}
			else
			{
				while (getchar() != '\n');
				printf("error：不存在该选项\n");
			}
			break;
		//exit
		case '0':
			if (getchar() == '\n')
			{
				break;
			}
			else
			{
				while (getchar() != '\n');
				printf("error：不存在该选项\n");
			}
		case '\n':
			printf("error：不存在该选项\n");
			break;
		//nothing
		default:
			if (getchar() == '\n')
			{
				Add_peoinfo(peonum);
				getchar();
			}
			else
			{
				while (getchar() != '\n');
				printf("error：不存在该选项\n");
			}
			break;
		}
	} while (input != '0');
	return 0;
}


// 
//测试scanf的用法：1、当从键盘输入的是%d，%s,%f时,不会考虑缓冲区里面的\n
				 //2、只有输入是%c时，\n也会被当做是字符取出来。
//当第一个输入是%s，下一个输入是%c时，需要用getchar将\n取出来。
//当用switch的输入是%c，但是输入时不小心输入是%s时，可以用while(getchar() == \n)来将缓冲区里面不需要的数据全部取出来。
//int main(void)
//{
//	char str = 0;
//	char str1[10] = { 0 };
//	char str2[10] = { 0 };
//	printf("请输入一个字符串:>");
//	scanf("%s", &str1);
//	printf("%s\n",str1);
//	//将换行符取出来
//	printf("%c", getchar());
//	printf("请输入单个字符:>");
//	scanf("%c", &str);
//	printf("%c", str);
//	return 0;
//}

//测试strcmp的排序规则
//比较的是首个字符的ASCII码，如strcmp("abcd"，"bbcd")返回的是-1.
//int main(void)
//{
//	char name1[10] = "刘凤凤";
//	char name2[10] = "王静";
//  char name3[10] = "朱静瑜";
//  char name4[10] = "杨倩";
//	int num = 0;
//	num = strcmp("abcd", "bcde");
//	printf("%d", num);
//	return 0;
//}


//测试冒泡排序的对错
//void Sort_peoinfo_test(char **ps,int num1)
//{
//	char temp[10] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < num1 - 1; i++)
//	{
//		for (j = i + 1; j < num1; j++)
//		{
//			if (1 == strcmp(ps[i], ps[j]))
//			{
//				strcpy(temp, ps[i]);
//				strcpy(ps[i], ps[j]);
//				strcpy(ps[j], temp);
//			}
//		}
//	}
//}
//
//
//int main(void)
//{
//	char ch1[10] = "niaho";
//	char ch2[10] = "abcd";
//	char ch3[10] = "mnm";
//	char ch4[10] = "bcd";
//	char* ps[10] = { ch1,ch2,ch3,ch4};
//	Sort_peoinfo_test(ps,4);
//	printf("%s,%s,%s,%s", ps[0], ps[1], ps[2],ps[3]);
//
//	return 0;
//}
