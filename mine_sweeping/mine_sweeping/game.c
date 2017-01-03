# define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

int aroud(char arr[Rows + 2][Cols + 2], char app[Rows + 2][Cols + 2], int x, int y) //�ѵ���ĵط�һ��û���׵ĵط�����ʾ������������ʾ��Χ�׵ĸ���
{
	int num = 0;
	int i = 0;
	int j = 0;
	int win = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
		if (i>0&&i<Rows+1&&j>0&&j<Cols+1&&arr[i][j] != '1')
		{
			num = del_mine(arr, i, j);
			if (app[i][j] == '*')
			{
				win++;
				app[i][j] = num + '0';
			}
		}
		}
	}
	return win;
}
	

int del_mine(char arr[Rows + 2][Cols + 2], int x, int y) //�жϵ���ĵط�һ�ܵ�����
{
	return ((arr[x - 1][y - 1] - '0') +
		(arr[x][y - 1] - '0') +
		(arr[x + 1][y - 1] - '0') +
		(arr[x - 1][y] - '0') +
		(arr[x + 1][y] - '0') +
		(arr[x - 1][y + 1] - '0') +
		(arr[x][y + 1] - '0') +
		(arr[x + 1][y + 1] - '0'));
}

void first(char arr[Rows + 2][Cols + 2], int x, int y)//�����һ���ȵ��ף��Ͱ��˸����Ƶ����λ��   
{
	if (arr[x][y] == '1')
	{
		arr[x][y] = '0';
		while (1)
		{
			x = rand()%10-1;
			y = rand()%10-1;
			if (arr[x][y] == '0')
			{
				arr[x][y] = '1';
				break;
			}
		}
	}
}

void set_mine(char arr[Rows + 2][Cols + 2], int rows, int cols)//������
{
	int count = NUM_MINE;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % 10+1;
		y = rand() % 10+1;
		if ('0' == arr[x][y])
		{
			count--;
			arr[x][y] = '1';
		}
	}
}

void display(char arr[Rows + 2][Cols + 2], int rows, int cols)    //��ӡ��
{
	int i = 0;
	int j = 0;
	printf("   ");
	for (i = 1; i <= rows; i++)
	{  
		printf("%d   ", i);
	}
	printf("\n  ________________________________________\n");
	for (i = 1; i <= rows; i++)
	{
		printf("%2d| ", i);
		for (j = 1; j <= cols; j++)
		{
			printf("%c | ", arr[i][j]);
		}
		printf("\n  |---|---|---|---|---|---|---|---|---|---|\n");
	}
}