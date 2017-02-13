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
		showtopic("*****通讯录*****\n\n\n");
		showtopic("添加联系人->  1\n");
		showtopic("查找联系人->  2\n");
		showtopic("删除联系人->  3\n");
		showtopic("显示电话簿->  4\n");
		showtopic("排序联系人->  5\n");
		showtopic("退出该系统-> 0\n");
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
			printf("按任意键继续....");
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
			printf("按任意键继续....");
			getch();
			break;
		case 5:

			getch();
			break;
		default:
			showtopic("输入有误请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
