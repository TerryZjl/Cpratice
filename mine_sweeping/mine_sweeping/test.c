# define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

enum lala
{
	EXIT,
	PLAY
};

void menu()
{
	printf("!!!**************************************!!!\n");
	printf("  !!!**** <welcome to play games> *****!!!\n");
	printf("  !!!***********  PLAY   1 ************!!!\n");
	printf("  !!!***********  EXIT   0 ************!!!\n");
	printf("!!!**************************************!!!\n");
}

void game()
{
	srand((unsigned int)time(NULL));
	char mine[Rows+2][Cols+2] = { 0 };           //用来布置雷的
	char show[Rows+2][Cols+2] = { 0 };           //用来显示给玩家看的
	int x = 0;
	int y = 0;
	int win = 0;        //计算排除了多少个空格
	int step = 0;      //计算步数
	memset(mine, '0', sizeof(char)*(Rows+2)*(Cols+2));
	memset(show, '*', sizeof(char)*(Rows + 2)*(Cols+2));
	set_mine(mine, Rows, Cols);
	//display(mine, Rows, Cols);      //用来测试时观察雷的位置
	printf("      <--------游戏进行中...------>\n");
	display(show, Rows, Cols);
	printf("您的当前的步数[ %d ]\n", step);
	printf("您排除的格子数[ %d ]\n", win);
	printf("请输入对应坐标：");
	while (win < (Rows*Cols - NUM_MINE))
	{
		scanf("%d%d", &x, &y);
		fflush(stdin);
		system("cls");
		if ((x <= Rows) && (x > 0) && (y <= Cols) && (y > 0))   //判断输入的坐标是否在给定坐标盘上
		{
			if ('*' == show[x][y])                      //判断展示的坐标盘上是否被赋过值，是否被前面输过的坐标所占用
			{
			    step++;                                   //计算步数
				if (step == 1)
				{
					first(mine, x, y);
				}
				if ('0' == mine[x][y])                   //判断输入的坐标是否踩中雷
				{
					win += aroud(mine, show, x, y);         //把点击的地方一周没有雷的地方都显示出来，并且显示周围雷的个数计算排除了多少个空格
					                                        //并返回排除没雷格子的数目
					if (win >= (Rows*Cols - NUM_MINE)) 
					{
						break;                                            
					}
					printf("      <--------游戏进行中...------>\n");
					display(show, Rows, Cols);
					printf("您的当前的步数[ %d ]\n", step);
					printf("您排除的格子数[ %d ]\n", win);
					printf("请输入对应坐标：");
				}
				else                        //若踩中雷，则游戏结束
				{
						printf("< %c%c%c  Game  over  %c%c%c >\n", 001, 001, 001, 001, 001, 001);
						del_mine(mine, x, y);
						show[x][y] = '@';
						display(show, Rows, Cols);
						printf("您的当前的步数[ %d ]\n", step);
						printf("您排除的格子数[ %d ]\n", win);
						printf("      <--------所有雷的位置------>\n");
						display(mine, Rows, Cols);
						system("pause");
						system("cls");
						break;
				}
			}
			else                             //若被赋过值、被前面输过的坐标所占用，则从新输入
			{
				printf("      <--------游戏进行中...------>\n");
				display(show, Rows, Cols);
				printf("您的当前的步数[ %d ]\n", step);
				printf("您排除的格子数[ %d ]\n", win);
				printf("该坐标已被占用,请重新输入：\a\a\a\n");
			}
		}
		else           //若输入的坐标不在棋盘上，则提示重新输入
		{
			printf("      <--------游戏进行中...------>\n");
			display(show, Rows, Cols);
			printf("您的当前的步数[ %d ]\n", step);
			printf("您排除的格子数[ %d ]\n", win);
			printf("输入有误,请重新输入：\a\a\a\n");
		}
	}
	if (win >= (Rows*Cols - NUM_MINE))    //判断所有雷排完则赢
	{
		printf("       <-----%c%c%c恭喜你赢了%c%c%c----->\n", 001, 001, 001, 001, 001, 001);
		display(show, Rows, Cols);
		printf("您的当前的步数[ %d ]\n", step);
		printf("您排除的格子数[ %d ]\n", win);
		//display(mine, Rows, Cols);
		system("pause");
		system("cls");
	}
}
int main()
{
	int key = 0;
	do
	{
		menu();
		printf("请选择0或1选项开始游戏：");
		scanf("%d", &key);
		fflush(stdin);
		switch (key)
		{
		case EXIT:system("cls");
				printf("%c%c%c谢谢使用%c%c%c\n", 001, 001, 001, 001, 001, 001);
				system("pause");
				exit(0);
		case PLAY:
			  system("cls");
		      game();
			  break;		
		default: printf("<!!无效选项!!>\n");
		        Sleep(1000);
		        system("cls");
		        break;
		}
	} while (key);
	return 0;
}