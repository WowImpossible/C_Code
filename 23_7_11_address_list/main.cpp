#define _CRT_SECURE_NO_WARNINGS 1
#include "contract.h"
//ͨѶ¼���������
#define MAX_Space 100

//1������Ŀ�����ã�ͨѶ¼����¼һЩ��ϵ�˵���Ϣ��
//2��û�п��ǵ��ĵط���1��û�п��ǵ�����������˵Ļ���û����ʾһ�¡�
	  //2��û�п��ǵ��������������(��������������ͦ�򵥵ģ�ֻ��Ҫ���ҵķ�������һ���������棬����ʾ�Ǹ��������Ԫ��)
     //3��ʹ�õ���һ��ȫ�ֱ�������¼ͨѶ¼����������̫�ã���Ϊȫ�ֱ����Ǵ�Ҷ����Ըı�ģ����Կ����ýṹ�����ԡ�
//3���������������������û�����Ҫ��ôд��(strcmp����������)


//��ʾͨѶ¼���������Լ���ʱ��������ĵ�ַ��
int num = 0;

//���ҵ������Ƿ���ͨѶ¼����,�ڷ����±꣬���ڷ���-1
int check = -2;

int main(void)
{
	char input = 0;
	//ѡ��ɾ���ķ�ʽ
	int del_choose = 0;
	peoinfo peonum[MAX_Space] = {0};
	do
	{
		//��ӡ�˵�
		menu();
		printf("��ѡ��Ҫִ�еĲ��� > ");
		scanf("%c", &input);
		//��ʼִ�в���
		switch (input)
		{
		//add
		case '1':
			//�������������Ϊscanf������%c����ʱ\nҲ�����ڻ����������ַ�ȡ�ߺ�\n�ͻᱻ����������ʹ��getchar�ѻ��з����ߡ�
            //����%s %d %f ʹ��scanf��ȡʱ�����\n���ڻ�������
			if (getchar() == '\n')
			{
				Add_peoinfo(peonum);
				getchar();
			}
			else
			{
				//ֱ���ѻ��������������ȫ��ȡ�ߣ�����\n
				while (getchar() != '\n');
				printf("error�������ڸ�ѡ��\n");
			}
			break;
		//delete
		case '2':
			if (getchar() == '\n')
			{
				if (Check_peoinfo())
				{
					printf("��������Ҫɾ���ķ�ʽ��1���������ɾ��   2����������ɾ��:>");
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
						printf("ѡ�����\n");
						break;
					}
				}
				else
				{
					printf("��Ϊ�յ�ͨѶ��û��ɾ���ı�Ҫ\n");
				}
			}
			else
			{
				while (getchar() != '\n');
				printf("error�������ڸ�ѡ��\n");
			}
			break;
		//search
		case '3':
			if (getchar() == '\n')
			{
				printf("������Ҫ��ѯ��ϵ������:>");
				Search_peoinfo(peonum);
			}
			else
			{
				while (getchar() != '\n');
				printf("error�������ڸ�ѡ��\n");
			}
			break;
		//modify
		case '4':
			if (getchar() == '\n')
			{
				printf("������Ҫ�޸ĵ���ϵ������:>");
				Modify_peoinfo(peonum);
			}
			else
			{
				while (getchar() != '\n');
				printf("error�������ڸ�ѡ��\n");
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
				printf("error�������ڸ�ѡ��\n");
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
				printf("error�������ڸ�ѡ��\n");
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
				printf("error�������ڸ�ѡ��\n");
			}
		case '\n':
			printf("error�������ڸ�ѡ��\n");
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
				printf("error�������ڸ�ѡ��\n");
			}
			break;
		}
	} while (input != '0');
	return 0;
}


// 
//����scanf���÷���1�����Ӽ����������%d��%s,%fʱ,���ῼ�ǻ����������\n
				 //2��ֻ��������%cʱ��\nҲ�ᱻ�������ַ�ȡ������
//����һ��������%s����һ��������%cʱ����Ҫ��getchar��\nȡ������
//����switch��������%c����������ʱ��С��������%sʱ��������while(getchar() == \n)�������������治��Ҫ������ȫ��ȡ������
//int main(void)
//{
//	char str = 0;
//	char str1[10] = { 0 };
//	char str2[10] = { 0 };
//	printf("������һ���ַ���:>");
//	scanf("%s", &str1);
//	printf("%s\n",str1);
//	//�����з�ȡ����
//	printf("%c", getchar());
//	printf("�����뵥���ַ�:>");
//	scanf("%c", &str);
//	printf("%c", str);
//	return 0;
//}

//����strcmp���������
//�Ƚϵ����׸��ַ���ASCII�룬��strcmp("abcd"��"bbcd")���ص���-1.
//int main(void)
//{
//	char name1[10] = "�����";
//	char name2[10] = "����";
//  char name3[10] = "�쾲�";
//  char name4[10] = "��ٻ";
//	int num = 0;
//	num = strcmp("abcd", "bcde");
//	printf("%d", num);
//	return 0;
//}


//����ð������ĶԴ�
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
