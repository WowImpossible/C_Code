#ifndef CONTRACT_H__
#define CONTRACT_H__


#include <stdio.h>
#include <string.h>

#define MAX_name 20
#define MAX_address 20
#define MAX_tel 20
#define MAX_sex 10
#define MAX_age 5

extern int num;
extern int check;

typedef struct Peoinfo
{
	//如果给的数组大小不合适，会导致显示的数字出现问题。
	//同时，最好的方法应该是将数组的大小用#define定义一下，改起来也好一点。
	char name[MAX_name];
	char tel[MAX_tel];
	char sex[MAX_sex];
	char address[MAX_address];
	char age[MAX_age];
}peoinfo;


void menu(void);
int Check_peoinfo(void);
void Add_peoinfo(peoinfo* ps);
void Show_peoinfo(peoinfo* ps);
void delete_sort(int index, peoinfo* ps);
void Delete_peoinfo_by_num(peoinfo* ps);
void Delete_peoinfo_by_name(peoinfo* ps);
void Modify_peoinfo(peoinfo* ps);
void Search_peoinfo(peoinfo* ps);
int index(peoinfo* ps, char* pinput);
void Sort_peoinfo(peoinfo* ps);


#endif // !CONTRACT_H__

