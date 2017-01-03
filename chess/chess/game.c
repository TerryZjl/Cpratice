# define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void is_board(char a[Rows][Cols],int rows, int cols)   //��ʼ������
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

void display_board(char a[Rows][Cols], int rows, int cols) //��ӡ����
{
	int i = 0;
	int j = 0;
	printf("<��Ϸ������>\n");
	printf("  1   2   3\n");
	for (i = 0; i < rows-1; i++)
	{
		printf("%d_%c_|_%c_|_%c_\n",i+1, a[i][0], a[i][1], a[i][2]);
	}
	printf("3 %c | %c | %c \n",a[i][0], a[i][1], a[i][2]);
}

void play_person(char a[Rows][Cols], int rows, int cols)        //�������
{
	int x = 0;
	int y = 0;
	printf("����������,�������Ӧ����:\n");
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
				printf("��׼������\a\a\a\n");
			}
		}
		else
		{
			printf("�����������Ӧ����:\a\a\a");
		}
	}
}
void play_computer(char a[Rows][Cols])  //��������
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (a[x][y] == ' ')
		{
			a[x][y] = 'O';
			printf("���Լ�����....\n");
			Sleep(1500);
			system("cls");
			break;
		}
	}
}
static int full(char a[Rows][Cols], int rows, int cols)    //����Ƿ�����
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (a[i][j] == ' ')
				return 0;  //û����
		}
	}
	return 1; //����
}

char dcide(char a[Rows][Cols], int rows, int cols)    //�ж�˭Ӯ
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) //�ж�����
	{
		if ((a[i][0] == a[i][1]) && (a[i][1] == a[i][2]) && (a[i][0] != ' '))
		{
			return a[i][0];
		}
	}
	for (i = 0; i < cols; i++)  //�ж�����
	{
		if ((a[0][i] == a[1][i]) && (a[1][i] == a[2][i]) && (a[0][i]!= ' '))
		{
			return a[0][i];
		}
	}
	if ((a[0][0] == a[1][1]) && (a[1][1] == a[2][2]) && (a[1][1] != ' '))  //�йٶԽ���
	{
		return a[1][1];
	}
	if ((a[0][2] == a[1][1]) && (a[1][1] == a[2][0]) && (a[1][1] != ' '))  //�йٶԽ���
	{
		return a[1][1];
	}
	if (full(a,rows, cols))
	{
		return 'T';  //ƽ��
	}
	return ' ';
}
