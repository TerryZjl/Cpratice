# define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

enum G                          //枚举类型  
{
	EXIT,
	PLAY
};
void menu()          //主界面
{
	printf("!!!**************************************!!!\n");
	printf("  !!!***********  PLAY   1 ************!!!\n");
	printf("  !!!***********  EXIT   0 ************!!!\n");
	printf("!!!**************************************!!!\n");
}

void game()     //玩游戏函数
{
	char set = 0;
	char a[Rows][Cols] = { 0 };
	is_board(a, Rows, Cols);
	system("cls");
	display_board(a, Rows, Cols);

	while (1)
	{

		play_person(a, Rows, Cols);    //玩家下棋
		display_board(a, Rows, Cols);   //打印棋盘
		set = dcide(a, Rows, Cols);   //判断谁赢
		if (set != ' ')
		{
			break;
		}
		play_computer(a);                 //电脑下棋
		display_board(a, Rows, Cols);    //打印棋盘
		set = dcide(a, Rows, Cols);    //判断谁赢
		if (set != ' ')
		{
			break;
		}
	}
	if (set == 'X')
	{
		printf("%c%c%c 666 你赢了 %c%c%c\n", 001, 001, 001, 001, 001, 001);
		system("pause");
		system("cls");
	}
	else if (set == 'O')
	{
		printf("%c%c%c 电脑赢了 %c%c%c\n",001,001,001,001,001,001);
		system("pause");
		system("cls");
	}
	else
	{
		printf("%c%c%c 平局了 %c%c%c\n", 001, 001, 001, 001, 001, 001);
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
		printf("请输入1或者0：");
		scanf("%d", &key);
		fflush(stdin);
		switch(key)
		{
		case EXIT:system("cls");      //退出游戏
			   printf("!!谢谢使用!!\n");
			   system("pause");
			   exit(0);
		case PLAY:                  //玩游戏
		    {
				  game();
		    }
			break;
		default: printf("<!!无效选项!!>\n");
			     Sleep(1000); 
				 system("cls");  
				 break;
		}

	} while (key);
	return 0;
 } 
