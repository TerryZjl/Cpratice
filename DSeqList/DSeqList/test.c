#include"DSeqList.h"

void menu()
{
	printf("***************************************\n");
	printf("***********   ͨѶ¼  *****************\n");
	printf("*****1.PushBack    2.PopBack***********\n");
	printf("*****3.PushFront   4.PopFront**********\n");
	printf("*****5.Find        6.Remove ***********\n");
	printf("*****7.RemoveAll   8.Show**************\n");
	printf("*****9.BinarySearch   *****************\n");
	printf("*****10.Sort       0.exit**************\n");
	printf("***************************************\n");
}
int main()
{
	SeqList con = {0};
	int tmep = 0;
	DataType num = 0;
	InitSeqList(&con);
	do
	{
		menu();
		printf("������ѡ��>");
		scanf("%d", &tmep);
		fflush(stdin);
		switch (tmep)
		{
		case 1:
			printf("������Ҫ�����Ԫ��>");
			scanf("%d", &num);
			PushBack(&con,num);
			break;
		case 2:
			PopBack(&con);
			break;
		case 3:
			printf("������Ҫ�����Ԫ��>");
			scanf("%d", &num);
			PushFront(&con, num);
			break;
		case 4:
			PopFront(&con);
			break;
		case 5:
		{
				  printf("������Ҫ���ҵ�Ԫ��>");
				  scanf("%d", &num);
				  int ret = Find(&con, num);
				  if (-1 == ret)
				  {
					  printf("û�ҵ�\n");
				  }
				  else
				  {
					  printf("%d���±�Ϊ%d��\n", num, ret);
				  }
		}
			break;
		case 6:
			printf("������Ҫɾ���ĵ�һ��Ԫ��>");
			scanf("%d", &num);
			Remove(&con, num);
			break;
		case 7:
			printf("������Ҫɾ����Ԫ��>");
			scanf("%d", &num);
			RemoveAll(&con, num);
			break;
		case 8:
			Show(&con);
			break;
		case 9:
		{
				  printf("������Ҫ���ҵ�Ԫ��>");
				  scanf("%d", &num);
				  int ret = BinarySearch(&con, num);
				  if (-1 == ret)
				  {
					  printf("û�ҵ�\n");
				  }
				  else
				  {
					  printf("%d���±�Ϊ%d��\n", num, ret);
				  }
		}
			break;
		case 10:
			Sort(&con);
			break;
		case 0:
			free(con.arr);
			exit(0);
			break;
		default:
			printf("��������,���������>\n");
			break;
		}
	} while(tmep);
		return 0;
}