# define _CRT_SECURE_NO_WARNINGS 1        //test.c
#include<stdio.h>
#include<Windows.h>
#include"communication.h"


int main()
{
	int input = 0;
	Contact con = { 0 };
	do
	{
		system("cls");
		printf("\n\n\n");
		showtopic("*****ͨѶ¼*****\n\n\n");
		showtopic("�����ϵ��->  1\n");
		showtopic("������ϵ��->  2\n");
		showtopic("ɾ����ϵ��->  3\n");
		showtopic("��ʾ�绰��->  4\n");
		showtopic("������ϵ��->  5\n");
		showtopic("�˳���ϵͳ-> 0\n");
		scanf("%d", &input);
		fflush(stdin);
		switch (input)
		{
		case 1:
			system("cls");
			AddContact(&con);

			break;
		case 2:
			system("cls");
			SearchContact(&con);
			printf("�����������....");
			getch();
			break;
		case 3:
			system("cls");
			DelContact(&con);
			getch();
			break;
		case 4:
			system("cls");
			showContact(&con);
			printf("�����������....");
			getch();
			break;
		case 5:

			getch();
			break;
		default:
			showtopic("������������������\n");
			break;
		}
	} while (input);
	return 0;
}
