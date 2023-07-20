#define _CRT_SECURE_NO_WARNINGS 1

#include "contract.h"

//判断通讯录里面是否有元素
int Check_peoinfo(void)
{
	if (num == 0)
	{
		return 0;
	}
	else
		return 1;
}


void menu(void)
{
	printf("*************************************\n");
	printf("******** 1 add      2 delete ********\n");
	printf("******** 3 search   4 modify ********\n");
	printf("******** 5 show     6 sort   ********\n");
	printf("************** 0 exit ***************\n");
	printf("*************************************\n");
}

void Add_peoinfo(peoinfo* ps)
{
	printf("请输入用户的个人信息\n");
	printf("名字:> ");
	scanf("%s", (ps + num)->name);
	printf("电话:> ");
	scanf("%s", (ps + num)->tel);
	printf("性别:> ");
	scanf("%s", (ps + num)->sex);
	printf("住址:> ");
	scanf("%s", (ps + num)->address);
	printf("年龄:> ");
	scanf("%s", (ps + num)->age);
	num++;
	printf("添加成功\n");
}

void Show_peoinfo(peoinfo* ps)
{
	//显示序号
	int show_num = 0;
	printf("\n%-5s\t%-5s\t%-10s\t%-5s\t%-10s\t%-4s\n",
		"序号",
		"名字",
		"电话",
		"性别",
		"地址",
		"年龄");
	if (Check_peoinfo())
	{
		if (num >= 1)
		{
			for (show_num = 0; show_num < num; show_num++)
			{
				printf("%-5d\t%-5s\t%-10s\t%-5s\t%-10s\t%-4s\n", 
					(show_num + 1), 
					(ps + show_num)->name, 
					(ps + show_num)->tel, 
					(ps + show_num)->sex, 
					(ps + show_num)->address, 
					(ps + show_num)->age);
			}
		}
	}
	else
	{
		printf("该通讯录为空\n");
	}
}


//寻找要删除的下标
int index(peoinfo* ps,char* pinput)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		if (!strcmp(ps[i].name, pinput))
		{
			break;
		}
	}
	if (i == num)
	{
		return -1;
	}
	else
	{
		return i;
	}
}

//将删除后的元素向前移
void delete_sort(int index, peoinfo* ps)
{
	int j = 0;
	for (j = index; j < num - 1; j++)
	{
		ps[j] = ps[j + 1];
	}
	num--;
}

void Delete_peoinfo_by_num(peoinfo* ps)
{
	int delete_num = 0;
	char delete_input = 0;
	if (Check_peoinfo())
	{
		Show_peoinfo(ps);
		printf("请输入要删除的号码(当前有%d个元素可删除)：>", num);
		scanf("%c", &delete_input);
		delete_num = delete_input - '1';
		while (delete_input != '0')
		{
			if (Check_peoinfo())
			{
				if (delete_num >= num || delete_num < 0)
				{
					printf("输入错误，请重新输入，或者输入0退出:>");
				}
				//删除元素(用后面的数据把前面的覆盖掉)
				else
				{
					delete_sort(delete_num, ps);
					printf("删除成功\n");
					Show_peoinfo(ps);
					break;
				}
				getchar();
				scanf("%c", &delete_input);
				delete_num = delete_input - '1';
			}
		}
		getchar();
	}
	else
	{
		printf("此为空的通讯，没有删除的必要\n");
	}
}

void Delete_peoinfo_by_name(peoinfo* ps)
{
	char delete_name[10];
	//确定是否真的删除信息
	char check_info = 0;
	int check1 = 0;
	if (Check_peoinfo())
	{
		Show_peoinfo(ps);
		printf("请输入要删除的名字：>", num);
		scanf("%s", delete_name);
		//查找是否存在
		check1 = index(ps, delete_name);
			
		if (-1 == check1)
		{
			printf("无此联系人信息\n");
		}
		else
		{
			printf("查找的信息为:\n");
			printf("\n%-5s\t%-5s\t%-10s\t%-5s\t%-10s\t%-4s\n",
				"序号",
				"名字",
				"电话",
				"性别",
				"地址",
				"年龄");
			printf("%-5d\t%-5s\t%-10s\t%-5s\t%-10s\t%-4s\n",
				(check1 + 1),
				(ps + check1)->name,
				(ps + check1)->tel,
				(ps + check1)->sex,
				(ps + check1)->address,
				(ps + check1)->age);
			while (getchar() != '\n');
			printf("确定删除该联系人信息吗？(y确定，n取消):>");
			scanf("%c", &check_info);
			switch (check_info)
			{
			case 'y':
				delete_sort(check1, ps);
				printf("删除成功\n");
				break;
			default:
				printf("取消删除操作\n");
				break;
			}
			Show_peoinfo(ps);
			while (getchar() != '\n');
		}
	}
	else
	{
		printf("此为空的通讯，没有删除的必要\n");
	}
}


void Search_peoinfo(peoinfo* ps)
{
	//查询
	char search_name[10] = { 0 };
	scanf("%s", search_name);
	check = index(ps, search_name);
	if (-1 == check)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("查询到的结果：\n");
		printf("\n%-5s\t%-5s\t%-10s\t%-5s\t%-10s\t%-4s\n",
			"序号",
			"名字",
			"电话",
			"性别",
			"地址",
			"年龄");
		printf("%-5d\t%-5s\t%-10s\t%-5s\t%-10s\t%-4s\n",
			(check + 1),
			(ps + check)->name,
			(ps + check)->tel,
			(ps + check)->sex,
			(ps + check)->address,
			(ps + check)->age);
		//取完数据之后，还有\n留在缓存区里面，要把它取出来，否则会影响后面取字符。
	}
	while(getchar() != '\n');
}

void Modify_peoinfo(peoinfo* ps)
{
	char modify_info[10] = { 0 };
	char modify[10] = {0}; 
	Search_peoinfo(ps);
	if (-1 != check)
	{
		printf("请输入要修改的信息:>");
		scanf("%s", modify_info);
		printf("请输入要修改成的内容:>");
		scanf("%s", modify);
		if (0 == strcmp(modify_info, "名字"))
		{
			strcpy((ps + check)->name, modify);
			printf("修改成功\n");
		}
		else if (0 == strcmp(modify_info, "电话"))
		{
			strcpy((ps + check)->tel, modify);
			printf("修改成功\n");
		}
		else if (0 == strcmp(modify_info, "性别"))
		{
			strcpy((ps + check)->sex, modify);
			printf("修改成功\n");
		}
		else if (0 == strcmp(modify_info, "地址"))
		{
			strcpy((ps + check)->address, modify);
			printf("修改成功\n");
		}
		else if (0 == strcmp(modify_info, "年龄"))
		{
			strcpy((ps + check)->age, modify);
			printf("修改成功\n");
		}
		else
		{
			printf("输入错误。修改失败");
		}
		//取走\n
		getchar();
	}
}

void Sort_peoinfo(peoinfo* ps)
{
	char temp[10] = { 0 };
	if (Check_peoinfo())
	{
		for (int i = 0; i < num - 1; i++)
		{
			for (int j = i + 1; j < num; j++)
			{
				if (1 == strcmp(ps[i].name, ps[j].name))
				{
					strcpy(temp, ps[i].name);
					strcpy(ps[i].name, ps[j].name);
					strcpy(ps[j].name, temp);
				}
			}
		}
	}
	else
	{
		printf("此通讯录为空\n");
	}
	Show_peoinfo(ps);
}


