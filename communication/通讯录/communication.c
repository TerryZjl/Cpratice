# define _CRT_SECURE_NO_WARNINGS 1         //game.c
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include"communication.h"

void swap(PeoInfo *a, PeoInfo *b)
{
	PeoInfo temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void showtopic(char *topic)
{
	char space[] = "                                       ";
	printf("%s %s\n", space + (strlen(topic) / 2), topic);
}
void InitContact(pContact pcon)
{
	pcon->count = 0;
	int i = 0;
	memset(pcon->contact, 0, MAX*sizeof(PeoInfo));
}
void AddContact(pContact pcon)
{
	if (pcon->count >= MAX)
	{
		printf("电话薄满了！\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", pcon->contact[pcon->count].name);
	printf("请输入性别：");
	scanf("%s", pcon->contact[pcon->count].sex);
	printf("请输入年龄:");
	scanf("%s", &pcon->contact[pcon->count].age);
	printf("请输入电话号码:");
	scanf("%s", pcon->contact[pcon->count].tele);
	printf("请输入地址:");
	scanf("%s", pcon->contact[pcon->count].addr);
	pcon->count++;

	printf("添加成功.......\n");

}
void DelContact(pContact pcon)
{
	int i = 0;
	char arr[20];
	printf("请输入你需要删除联系人的姓名\n");
	scanf("%s", arr);
	for (i = 0; i < pcon->count; i++)
	{
		if (strcmp(pcon->contact[i].name, arr) == 0)
		{
			/*memset(pcon + i - 1, 0, sizeof(PeoInfo));*/
			swap(&pcon->contact[i], &pcon->contact[(pcon->count) - 1]);
			printf("删除成功");
		}
	}
	pcon->count--;


}
void SearchContact(pContact pcon)
{
	char arr[20];
	int i = 0;
	printf("请输入需要查找联系人的名字~\n");
	scanf("%s", &arr);
	for (i = 0; i < pcon->count; i++)
	{
		if (strcmp(pcon->contact[i].name, arr) == 0)
		{
			printf("%10s%5s%6d%7s%8s\n",
				pcon->contact[i].name,
				pcon->contact[i].sex,
				pcon->contact[i].age,
				pcon->contact[i].tele,
				pcon->contact[i].addr);
			return 0;
		}
	}

	printf("你输入的联系人不存在在电话薄上");
}

void showContact(pContact pcon)
{
	int i = 0;
	printf("%10s%5s%6s%7s%8s\n", "name", "sex", "age", "tele", "addr");
	for (i = 0; i < pcon->count; i++)
	{
		printf("%10s%5s%6d%7s%8s\n",
			pcon->contact[i].name,
			pcon->contact[i].sex,
			pcon->contact[i].age,
			pcon->contact[i].tele,
			pcon->contact[i].addr);
	}
}
void sortContact(pContact pcon){
	int i = 0;
	int j = 0;
	PeoInfo *t;
	PeoInfo *p1;
	PeoInfo *p2;
	for (i = 0; i < MAX - 1; i++)
	for (j = 0; j < MAX - i - 1; j++)
	{
		if (strcmp(pcon->contact[i].name, pcon->contact[i - 1].name) < 0)
		{
			/*	swap(&pcon->contact[i], &pcon->contact[i - 1]);*/
		}
	}
}
