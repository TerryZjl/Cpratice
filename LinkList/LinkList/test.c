#include"LinkList.h"

pNode searchInsert(pList plist, DataType d)  
{
	int i = 0;
	pNode cur = plist;
	while (i < d - 1 && cur != NULL)  //找到指定要插入的位置的地址
	{
		i++;
		cur = cur->next;
	}
	if (i>d - 1 || cur == NULL)       //判断i输入的是否大于链表长度或者小于等于零
	{
		return NULL;
	}
	return cur;
}

pNode searchErase(pList plist, DataType d)  //找到指定要删除的地址
{
	int i = 0;
	pNode cur = plist;
	while (cur->next != NULL&&i<d-1)
	{
		i++;
		cur = cur->next;
	}
	if (i>d - 1 || cur->next == NULL)
	{
		return NULL;
	}
	return cur;
}

void menu()
{
	printf("***************************************\n");
	printf("***********   LinkList  ****************\n");
	printf("*****1.PushBack    2.PopBack***********\n");
	printf("*****3.PushFront   4.PopFront**********\n");
	printf("*****5.Find        6.Remove ***********\n");
	printf("*****7.RemoveAll   8.ShowList***********\n");
	printf("*****9.Insert      10.Erase*************\n");
	printf("*****11.Destory    0.exi*****************\n");
	printf("***************************************\n");
}
void test()
{
	int tmep = 0;
	int i = 0;
	DataType num = 0;
	pList plist;
	pNode ret = NULL;
	InitLinkList(&plist);
	do
	{
		menu();
		printf("请输入选项>");
		scanf("%d", &tmep);
		fflush(stdin);
		switch (tmep)
		{
		case 1:
			printf("请输入要从尾插入的元素>");
			scanf("%d", &num);
			PushBack(&plist,num);
			break;
		case 2:
			PopBack(&plist);
			break;
		case 3:
			printf("请输入要从头插入的元素>");
			scanf("%d", &num);
			PushFront(&plist,num);
			break;
		case 4:
			PopFront(&plist);
			break;
		case 5:
		{
				  printf("请输入要查找的元素>");
				  scanf("%d", &num);
				  ret = Find(plist, num);
				  if (ret != NULL)
				  {
					  printf("%d找到了！地址：%p\n", num, ret);
				  }
				  else
				  {
					  printf("没有要查找的元素\n");
				  }
		}
			break;
		case 6:
			printf("请输入要删除第一个的元素>");
			scanf("%d", &num);
			Remove(&plist,num);
			break;
		case 7:
			printf("请输入要删除的元素>");
			scanf("%d", &num);
			RemoveAll(&plist, num);
			break;
		case 8:
			ShowList(plist);
			break;
		case 9:
		{
				  printf("请输入要在第几个数字的后面插入元素>");
				  scanf("%d", &i);
				  ret = searchInsert(plist, i);
				  if (ret == NULL)
				  {
					  printf("输入有误\n");
				  }
				  else
				  {
					  printf("请输入要插入的的元素>");
					  scanf("%d", &num);
					  Insert(&plist, ret, num);
				  }
				  /*Insert(&plist,i,num);*/
		}
				break;
		case 10:
		{
				   printf("请输入要删除第几个数字的后面的元素>");
				   scanf("%d", &i);
				   ret = searchErase(plist, i);
				   if (ret == NULL)
				   {
					   printf("输入有误\n");
				   }
				   else
				   {
					   Erase(&plist, ret);
				   }
				   //Erase(&plist, i);
		}
			break;
		case 11:
			Destory(&plist);
			break;
		case 0:
			Destory(&plist);
			exit(0);
			break;
		default:
			printf("输入有误,请从新输入>\n");
			break;
		}
	} while (tmep);
	return;
}
int main()
{
	test();
	return 0;
}