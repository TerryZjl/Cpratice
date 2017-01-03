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
	char mine[Rows+2][Cols+2] = { 0 };           //���������׵�
	char show[Rows+2][Cols+2] = { 0 };           //������ʾ����ҿ���
	int x = 0;
	int y = 0;
	int win = 0;        //�����ų��˶��ٸ��ո�
	int step = 0;      //���㲽��
	memset(mine, '0', sizeof(char)*(Rows+2)*(Cols+2));
	memset(show, '*', sizeof(char)*(Rows + 2)*(Cols+2));
	set_mine(mine, Rows, Cols);
	//display(mine, Rows, Cols);      //��������ʱ�۲��׵�λ��
	printf("      <--------��Ϸ������...------>\n");
	display(show, Rows, Cols);
	printf("���ĵ�ǰ�Ĳ���[ %d ]\n", step);
	printf("���ų��ĸ�����[ %d ]\n", win);
	printf("�������Ӧ���꣺");
	while (win < (Rows*Cols - NUM_MINE))
	{
		scanf("%d%d", &x, &y);
		fflush(stdin);
		system("cls");
		if ((x <= Rows) && (x > 0) && (y <= Cols) && (y > 0))   //�ж�����������Ƿ��ڸ�����������
		{
			if ('*' == show[x][y])                      //�ж�չʾ�����������Ƿ񱻸���ֵ���Ƿ�ǰ�������������ռ��
			{
			    step++;                                   //���㲽��
				if (step == 1)
				{
					first(mine, x, y);
				}
				if ('0' == mine[x][y])                   //�ж�����������Ƿ������
				{
					win += aroud(mine, show, x, y);         //�ѵ���ĵط�һ��û���׵ĵط�����ʾ������������ʾ��Χ�׵ĸ��������ų��˶��ٸ��ո�
					                                        //�������ų�û�׸��ӵ���Ŀ
					if (win >= (Rows*Cols - NUM_MINE)) 
					{
						break;                                            
					}
					printf("      <--------��Ϸ������...------>\n");
					display(show, Rows, Cols);
					printf("���ĵ�ǰ�Ĳ���[ %d ]\n", step);
					printf("���ų��ĸ�����[ %d ]\n", win);
					printf("�������Ӧ���꣺");
				}
				else                        //�������ף�����Ϸ����
				{
						printf("< %c%c%c  Game  over  %c%c%c >\n", 001, 001, 001, 001, 001, 001);
						del_mine(mine, x, y);
						show[x][y] = '@';
						display(show, Rows, Cols);
						printf("���ĵ�ǰ�Ĳ���[ %d ]\n", step);
						printf("���ų��ĸ�����[ %d ]\n", win);
						printf("      <--------�����׵�λ��------>\n");
						display(mine, Rows, Cols);
						system("pause");
						system("cls");
						break;
				}
			}
			else                             //��������ֵ����ǰ�������������ռ�ã����������
			{
				printf("      <--------��Ϸ������...------>\n");
				display(show, Rows, Cols);
				printf("���ĵ�ǰ�Ĳ���[ %d ]\n", step);
				printf("���ų��ĸ�����[ %d ]\n", win);
				printf("�������ѱ�ռ��,���������룺\a\a\a\n");
			}
		}
		else           //����������겻�������ϣ�����ʾ��������
		{
			printf("      <--------��Ϸ������...------>\n");
			display(show, Rows, Cols);
			printf("���ĵ�ǰ�Ĳ���[ %d ]\n", step);
			printf("���ų��ĸ�����[ %d ]\n", win);
			printf("��������,���������룺\a\a\a\n");
		}
	}
	if (win >= (Rows*Cols - NUM_MINE))    //�ж�������������Ӯ
	{
		printf("       <-----%c%c%c��ϲ��Ӯ��%c%c%c----->\n", 001, 001, 001, 001, 001, 001);
		display(show, Rows, Cols);
		printf("���ĵ�ǰ�Ĳ���[ %d ]\n", step);
		printf("���ų��ĸ�����[ %d ]\n", win);
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
		printf("��ѡ��0��1ѡ�ʼ��Ϸ��");
		scanf("%d", &key);
		fflush(stdin);
		switch (key)
		{
		case EXIT:system("cls");
				printf("%c%c%cллʹ��%c%c%c\n", 001, 001, 001, 001, 001, 001);
				system("pause");
				exit(0);
		case PLAY:
			  system("cls");
		      game();
			  break;		
		default: printf("<!!��Чѡ��!!>\n");
		        Sleep(1000);
		        system("cls");
		        break;
		}
	} while (key);
	return 0;
}