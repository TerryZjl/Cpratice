# define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

enum G                          //ö������  
{
	EXIT,
	PLAY
};
void menu()          //������
{
	printf("!!!**************************************!!!\n");
	printf("  !!!***********  PLAY   1 ************!!!\n");
	printf("  !!!***********  EXIT   0 ************!!!\n");
	printf("!!!**************************************!!!\n");
}

void game()     //����Ϸ����
{
	char set = 0;
	char a[Rows][Cols] = { 0 };
	is_board(a, Rows, Cols);
	system("cls");
	display_board(a, Rows, Cols);

	while (1)
	{

		play_person(a, Rows, Cols);    //�������
		display_board(a, Rows, Cols);   //��ӡ����
		set = dcide(a, Rows, Cols);   //�ж�˭Ӯ
		if (set != ' ')
		{
			break;
		}
		play_computer(a);                 //��������
		display_board(a, Rows, Cols);    //��ӡ����
		set = dcide(a, Rows, Cols);    //�ж�˭Ӯ
		if (set != ' ')
		{
			break;
		}
	}
	if (set == 'X')
	{
		printf("%c%c%c 666 ��Ӯ�� %c%c%c\n", 001, 001, 001, 001, 001, 001);
		system("pause");
		system("cls");
	}
	else if (set == 'O')
	{
		printf("%c%c%c ����Ӯ�� %c%c%c\n",001,001,001,001,001,001);
		system("pause");
		system("cls");
	}
	else
	{
		printf("%c%c%c ƽ���� %c%c%c\n", 001, 001, 001, 001, 001, 001);
		system("pause");
		system("cls");
	}
}

int main()
{
	int key = 0;
	char arr[Rows][Cols] = { 0 };
	do
	{
		menu();
		printf("������1����0��");
		scanf("%d", &key);
		fflush(stdin);
		switch(key)
		{
		case EXIT:system("cls");      //�˳���Ϸ
			   printf("!!ллʹ��!!\n");
			   system("pause");
			   exit(0);
		case PLAY:                  //����Ϸ
		    {
				  game();
		    }
			break;
		default: printf("<!!��Чѡ��!!>\n");
			     Sleep(1000); 
				 system("cls");  
				 break;
		}

	} while (key);
	return 0;
 } 
