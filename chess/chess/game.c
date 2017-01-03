# define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void is_board(char a[Rows][Cols],int rows, int cols)   //初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			a[i][j] = ' ';
	}
	return 0;
}

void display_board(char a[Rows][Cols], int rows, int cols) //打印棋盘
{
	int i = 0;
	int j = 0;
	printf("<游戏进行中>\n");
	printf("  1   2   3\n");
	for (i = 0; i < rows-1; i++)
	{
		printf("%d_%c_|_%c_|_%c_\n",i+1, a[i][0], a[i][1], a[i][2]);
	}
	printf("3 %c | %c | %c \n",a[i][0], a[i][1], a[i][2]);
}

void play_person(char a[Rows][Cols], int rows, int cols)        //玩家下棋
{
	int x = 0;
	int y = 0;
	printf("该你下棋了,请输入对应坐标:\n");
	while (1)
	{
		scanf("%d%d", &x, &y);
		fflush(stdin);
		x--;
		y--;
		if ((x >= 0) && (x <= rows) && (y >= 0) && (y <= cols))
		{
			if (a[x][y] == ' ')
			{
				a[x][y] = 'X';
				system("cls");
				break;
			}
			else
			{
				printf("看准了在下\a\a\a\n");
			}
		}
		else
		{
			printf("请重新输入对应坐标:\a\a\a");
		}
	}
}
void play_computer(char a[Rows][Cols])  //电脑下棋
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (a[x][y] == ' ')
		{
			a[x][y] = 'O';
			printf("电脑计算中....\n");
			Sleep(1500);
			system("cls");
			break;
		}
	}
}
static int full(char a[Rows][Cols], int rows, int cols)    //检查是否填满
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (a[i][j] == ' ')
				return 0;  //没有满
		}
	}
	return 1; //满了
}

char dcide(char a[Rows][Cols], int rows, int cols)    //判断谁赢
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) //判断三行
	{
		if ((a[i][0] == a[i][1]) && (a[i][1] == a[i][2]) && (a[i][0] != ' '))
		{
			return a[i][0];
		}
	}
	for (i = 0; i < cols; i++)  //判断三列
	{
		if ((a[0][i] == a[1][i]) && (a[1][i] == a[2][i]) && (a[0][i]!= ' '))
		{
			return a[0][i];
		}
	}
	if ((a[0][0] == a[1][1]) && (a[1][1] == a[2][2]) && (a[1][1] != ' '))  //判官对角线
	{
		return a[1][1];
	}
	if ((a[0][2] == a[1][1]) && (a[1][1] == a[2][0]) && (a[1][1] != ' '))  //判官对角线
	{
		return a[1][1];
	}
	if (full(a,rows, cols))
	{
		return 'T';  //平局
	}
	return ' ';
}
