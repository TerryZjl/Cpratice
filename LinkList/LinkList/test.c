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
	while (cur->next != NULL&&i<d - 1)
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
	printf("*****12.删除无头单链表非尾结点***********\n");
	printf("*****13.翻转      14.在当前结点前插一个数*\n");
	printf("*****15.合并两个有序链表非递归************\n");
	printf("*****16.链表的冒泡排序    ***************\n");
	printf("*****17.递归合并两个有序链表************\n");
	printf("***************************************\n");
}
void test()
{
	int tmep = 0;
	int i = 0;
	DataType num = 0;
	pList plist;
	pList plist2;
	pNode ret = NULL;
	InitLinkList(&plist);
	InitLinkList(&plist2);
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
			PushBack(&plist, num);
			break;
		case 2:
			PopBack(&plist);
			break;
		case 3:
			printf("请输入要从头插入的元素>");
			scanf("%d", &num);
			PushFront(&plist, num);
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
			Remove(&plist, num);
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
		case 12:
		{
				   printf("请输入要删除的非尾结点\n");
				   scanf("%d", &num);
				   ret = Find(plist, num);
				   EraseNotTail(ret);
		}
			break;
		case 13:
		{
				   ReverseList(&plist);
		}
			break;
		case 14:
		{
				   printf("请要插入数据位置的当前结点值\n");
				   scanf("%d", &num);
				   ret = Find(plist, num);
				   if (ret == NULL)
				   {
					   printf("输入有误\n");
				   }
				   else
				   {
					   printf("请输入当前结点前要插入的数据\n");
					   scanf("%d", &i);
					   InsertFrontNode(ret, i);
				   }
		}
			break;
		case 15:
		{
				   PushBack(&plist2, 1);
				   PushBack(&plist2, 3);
				   PushBack(&plist2, 5);
				   PushBack(&plist2, 7);
				   plist = Merge(plist, plist2);
		}
			break;
		case 16:
		{
				   ShowList(plist);
				   BubbleSort(&plist);
				   ShowList(plist);
		}
			break;
		case 17:
		{
				   PushBack(&plist2, 1);
				   PushBack(&plist2, 3);
				   ShowList(plist);
				   ShowList(plist2);
				   printf("合并后:\n");
				   plist = Merge2(plist, plist2);
				   ShowList(plist);
		}
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

void test2()
{
	pList plist;
	pList plist2;
	pNode ret = NULL;
	InitLinkList(&plist);
	InitLinkList(&plist2);
	PushBack(&plist, 1);
	PushBack(&plist, 3);
	PushBack(&plist, 5);
	PushBack(&plist, 7);
	PushBack(&plist, 8);

	PushBack(&plist2, 2);
	PushBack(&plist2, 4);
	PushBack(&plist2, 6);
	PushBack(&plist2, 1);
	PushBack(&plist2, 9);

	//判断两条无环链表是否相交
	Find(plist, 8)->next = Find(plist2, 6);
	ret = CheckCross(plist, plist2);
	if (ret == 0)
	{
		printf("不相交\n");
	}
	else
	{
		printf("相交\n");
	}

	//若有环，找到环的入口点
	//Find(plist, 8)->next = plist;
	//ret = GetNode(plist, CheckCycle(plist));
	//printf("%d\n", ret->data);
	
	//若有环，求环的长度
	/*Find(plist, 8)->next = plist->next;
    ret = GetCircleLength(CheckCycle(plist));
	printf("%d\n", ret);*/

	//检查是否带环
	/*Find(plist, 8)->next = plist;
	ret = CheckCycle(plist);
	if (ret == NULL)
	{
		printf("无环\n");
	}
	else
	{
		printf("有环\n");
	}
    */

	//逆序打印
	/*ShowList(plist);
	PrintReversely(plist);*/
	
	//约瑟夫环
	/*Find(plist,8)->next = plist;
	ret = JosephCycle(&plist, 3);
	printf("end:%d\n", ret->data);*/

	//删除倒数第K个
	/*DelKNode(&plist,4);
	ShowList(plist);*/

	//查找中间的
	/*ret = FindMidNode(plist);
	printf("%d\n", ret->data);*/

	/*Destory(&plist);*/
}


void test3()
{
	pComplexList plist;
	pComplexNode ret = NULL;
	InitLinkList(&plist);
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);

	Find(plist, 1)->randmo = Find(plist, 4);
	Find(plist, 2)->randmo = Find(plist, 1);
	Find(plist, 3)->randmo = Find(plist, 2);
	Find(plist, 4)->randmo = Find(plist, 3);
	printf("正版\n");
	PrintComplexList(plist);
    ret = CopyComplexList(plist);
	printf("盗版\n");
	PrintComplexList(ret);
}

int main()
{
	test3();
	system("pause");
	return 0;
}