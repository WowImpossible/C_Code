#define _CRT_SECURE_NO_WARNINGS 1

#include "contract.h"

//�ж�ͨѶ¼�����Ƿ���Ԫ��
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
	printf("�������û��ĸ�����Ϣ\n");
	printf("����:> ");
	scanf("%s", (ps + num)->name);
	printf("�绰:> ");
	scanf("%s", (ps + num)->tel);
	printf("�Ա�:> ");
	scanf("%s", (ps + num)->sex);
	printf("סַ:> ");
	scanf("%s", (ps + num)->address);
	printf("����:> ");
	scanf("%s", (ps + num)->age);
	num++;
	printf("��ӳɹ�\n");
}

void Show_peoinfo(peoinfo* ps)
{
	//��ʾ���
	int show_num = 0;
	printf("\n%-5s\t%-5s\t%-10s\t%-5s\t%-10s\t%-4s\n",
		"���",
		"����",
		"�绰",
		"�Ա�",
		"��ַ",
		"����");
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
		printf("��ͨѶ¼Ϊ��\n");
	}
}


//Ѱ��Ҫɾ�����±�
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

//��ɾ�����Ԫ����ǰ��
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
		printf("������Ҫɾ���ĺ���(��ǰ��%d��Ԫ�ؿ�ɾ��)��>", num);
		scanf("%c", &delete_input);
		delete_num = delete_input - '1';
		while (delete_input != '0')
		{
			if (Check_peoinfo())
			{
				if (delete_num >= num || delete_num < 0)
				{
					printf("����������������룬��������0�˳�:>");
				}
				//ɾ��Ԫ��(�ú�������ݰ�ǰ��ĸ��ǵ�)
				else
				{
					delete_sort(delete_num, ps);
					printf("ɾ���ɹ�\n");
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
		printf("��Ϊ�յ�ͨѶ��û��ɾ���ı�Ҫ\n");
	}
}

void Delete_peoinfo_by_name(peoinfo* ps)
{
	char delete_name[10];
	//ȷ���Ƿ����ɾ����Ϣ
	char check_info = 0;
	int check1 = 0;
	if (Check_peoinfo())
	{
		Show_peoinfo(ps);
		printf("������Ҫɾ�������֣�>", num);
		scanf("%s", delete_name);
		//�����Ƿ����
		check1 = index(ps, delete_name);
			
		if (-1 == check1)
		{
			printf("�޴���ϵ����Ϣ\n");
		}
		else
		{
			printf("���ҵ���ϢΪ:\n");
			printf("\n%-5s\t%-5s\t%-10s\t%-5s\t%-10s\t%-4s\n",
				"���",
				"����",
				"�绰",
				"�Ա�",
				"��ַ",
				"����");
			printf("%-5d\t%-5s\t%-10s\t%-5s\t%-10s\t%-4s\n",
				(check1 + 1),
				(ps + check1)->name,
				(ps + check1)->tel,
				(ps + check1)->sex,
				(ps + check1)->address,
				(ps + check1)->age);
			while (getchar() != '\n');
			printf("ȷ��ɾ������ϵ����Ϣ��(yȷ����nȡ��):>");
			scanf("%c", &check_info);
			switch (check_info)
			{
			case 'y':
				delete_sort(check1, ps);
				printf("ɾ���ɹ�\n");
				break;
			default:
				printf("ȡ��ɾ������\n");
				break;
			}
			Show_peoinfo(ps);
			while (getchar() != '\n');
		}
	}
	else
	{
		printf("��Ϊ�յ�ͨѶ��û��ɾ���ı�Ҫ\n");
	}
}


void Search_peoinfo(peoinfo* ps)
{
	//��ѯ
	char search_name[10] = { 0 };
	scanf("%s", search_name);
	check = index(ps, search_name);
	if (-1 == check)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("��ѯ���Ľ����\n");
		printf("\n%-5s\t%-5s\t%-10s\t%-5s\t%-10s\t%-4s\n",
			"���",
			"����",
			"�绰",
			"�Ա�",
			"��ַ",
			"����");
		printf("%-5d\t%-5s\t%-10s\t%-5s\t%-10s\t%-4s\n",
			(check + 1),
			(ps + check)->name,
			(ps + check)->tel,
			(ps + check)->sex,
			(ps + check)->address,
			(ps + check)->age);
		//ȡ������֮�󣬻���\n���ڻ��������棬Ҫ����ȡ�����������Ӱ�����ȡ�ַ���
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
		printf("������Ҫ�޸ĵ���Ϣ:>");
		scanf("%s", modify_info);
		printf("������Ҫ�޸ĳɵ�����:>");
		scanf("%s", modify);
		if (0 == strcmp(modify_info, "����"))
		{
			strcpy((ps + check)->name, modify);
			printf("�޸ĳɹ�\n");
		}
		else if (0 == strcmp(modify_info, "�绰"))
		{
			strcpy((ps + check)->tel, modify);
			printf("�޸ĳɹ�\n");
		}
		else if (0 == strcmp(modify_info, "�Ա�"))
		{
			strcpy((ps + check)->sex, modify);
			printf("�޸ĳɹ�\n");
		}
		else if (0 == strcmp(modify_info, "��ַ"))
		{
			strcpy((ps + check)->address, modify);
			printf("�޸ĳɹ�\n");
		}
		else if (0 == strcmp(modify_info, "����"))
		{
			strcpy((ps + check)->age, modify);
			printf("�޸ĳɹ�\n");
		}
		else
		{
			printf("��������޸�ʧ��");
		}
		//ȡ��\n
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
		printf("��ͨѶ¼Ϊ��\n");
	}
	Show_peoinfo(ps);
}


