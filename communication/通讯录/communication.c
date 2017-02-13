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
		printf("�绰�����ˣ�\n");
		return;
	}
	printf("������������");
	scanf("%s", pcon->contact[pcon->count].name);
	printf("�������Ա�");
	scanf("%s", pcon->contact[pcon->count].sex);
	printf("����������:");
	scanf("%s", &pcon->contact[pcon->count].age);
	printf("������绰����:");
	scanf("%s", pcon->contact[pcon->count].tele);
	printf("�������ַ:");
	scanf("%s", pcon->contact[pcon->count].addr);
	pcon->count++;

	printf("��ӳɹ�.......\n");

}
void DelContact(pContact pcon)
{
	int i = 0;
	char arr[20];
	printf("����������Ҫɾ����ϵ�˵�����\n");
	scanf("%s", arr);
	for (i = 0; i < pcon->count; i++)
	{
		if (strcmp(pcon->contact[i].name, arr) == 0)
		{
			/*memset(pcon + i - 1, 0, sizeof(PeoInfo));*/
			swap(&pcon->contact[i], &pcon->contact[(pcon->count) - 1]);
			printf("ɾ���ɹ�");
		}
	}
	pcon->count--;


}
void SearchContact(pContact pcon)
{
	char arr[20];
	int i = 0;
	printf("��������Ҫ������ϵ�˵�����~\n");
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

	printf("���������ϵ�˲������ڵ绰����");
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
