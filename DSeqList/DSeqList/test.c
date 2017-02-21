#include"DSeqList.h"

void menu()
{
	printf("***************************************\n");
	printf("***********   通讯录  *****************\n");
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
		printf("请输入选项>");
		scanf("%d", &tmep);
		fflush(stdin);
		switch (tmep)
		{
		case 1:
			printf("请输入要插入的元素>");
			scanf("%d", &num);
			PushBack(&con,num);
			break;
		case 2:
			PopBack(&con);
			break;
		case 3:
			printf("请输入要插入的元素>");
			scanf("%d", &num);
			PushFront(&con, num);
			break;
		case 4:
			PopFront(&con);
			break;
		case 5:
		{
				  printf("请输入要查找的元素>");
				  scanf("%d", &num);
				  int ret = Find(&con, num);
				  if (-1 == ret)
				  {
					  printf("没找到\n");
				  }
				  else
				  {
					  printf("%d在下标为%d处\n", num, ret);
				  }
		}
			break;
		case 6:
			printf("请输入要删除的第一个元素>");
			scanf("%d", &num);
			Remove(&con, num);
			break;
		case 7:
			printf("请输入要删除的元素>");
			scanf("%d", &num);
			RemoveAll(&con, num);
			break;
		case 8:
			Show(&con);
			break;
		case 9:
		{
				  printf("请输入要查找的元素>");
				  scanf("%d", &num);
				  int ret = BinarySearch(&con, num);
				  if (-1 == ret)
				  {
					  printf("没找到\n");
				  }
				  else
				  {
					  printf("%d在下标为%d处\n", num, ret);
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
			printf("输入有误,请从新输入>\n");
			break;
		}
	} while(tmep);
		return 0;
}