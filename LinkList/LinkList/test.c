#include"LinkList.h"

pNode searchInsert(pList plist, DataType d)
{
	int i = 0;
	pNode cur = plist;
	while (i < d - 1 && cur != NULL)  //�ҵ�ָ��Ҫ�����λ�õĵ�ַ
	{
		i++;
		cur = cur->next;
	}
	if (i>d - 1 || cur == NULL)       //�ж�i������Ƿ���������Ȼ���С�ڵ�����
	{
		return NULL;
	}
	return cur;
}

pNode searchErase(pList plist, DataType d)  //�ҵ�ָ��Ҫɾ���ĵ�ַ
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
	printf("*****12.ɾ����ͷ�������β���***********\n");
	printf("*****13.��ת      14.�ڵ�ǰ���ǰ��һ����*\n");
	printf("*****15.�ϲ�������������ǵݹ�************\n");
	printf("*****16.�����ð������    ***************\n");
	printf("*****17.�ݹ�ϲ�������������************\n");
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
		printf("������ѡ��>");
		scanf("%d", &tmep);
		fflush(stdin);
		switch (tmep)
		{
		case 1:
			printf("������Ҫ��β�����Ԫ��>");
			scanf("%d", &num);
			PushBack(&plist, num);
			break;
		case 2:
			PopBack(&plist);
			break;
		case 3:
			printf("������Ҫ��ͷ�����Ԫ��>");
			scanf("%d", &num);
			PushFront(&plist, num);
			break;
		case 4:
			PopFront(&plist);
			break;
		case 5:
		{
				  printf("������Ҫ���ҵ�Ԫ��>");
				  scanf("%d", &num);
				  ret = Find(plist, num);
				  if (ret != NULL)
				  {
					  printf("%d�ҵ��ˣ���ַ��%p\n", num, ret);
				  }
				  else
				  {
					  printf("û��Ҫ���ҵ�Ԫ��\n");
				  }
		}
			break;
		case 6:
			printf("������Ҫɾ����һ����Ԫ��>");
			scanf("%d", &num);
			Remove(&plist, num);
			break;
		case 7:
			printf("������Ҫɾ����Ԫ��>");
			scanf("%d", &num);
			RemoveAll(&plist, num);
			break;
		case 8:
			ShowList(plist);
			break;
		case 9:
		{
				  printf("������Ҫ�ڵڼ������ֵĺ������Ԫ��>");
				  scanf("%d", &i);
				  ret = searchInsert(plist, i);
				  if (ret == NULL)
				  {
					  printf("��������\n");
				  }
				  else
				  {
					  printf("������Ҫ����ĵ�Ԫ��>");
					  scanf("%d", &num);
					  Insert(&plist, ret, num);
				  }
				  /*Insert(&plist,i,num);*/
		}
			break;
		case 10:
		{
				   printf("������Ҫɾ���ڼ������ֵĺ����Ԫ��>");
				   scanf("%d", &i);
				   ret = searchErase(plist, i);
				   if (ret == NULL)
				   {
					   printf("��������\n");
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
				   printf("������Ҫɾ���ķ�β���\n");
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
				   printf("��Ҫ��������λ�õĵ�ǰ���ֵ\n");
				   scanf("%d", &num);
				   ret = Find(plist, num);
				   if (ret == NULL)
				   {
					   printf("��������\n");
				   }
				   else
				   {
					   printf("�����뵱ǰ���ǰҪ���������\n");
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
				   printf("�ϲ���:\n");
				   plist = Merge2(plist, plist2);
				   ShowList(plist);
		}
				break;
		case 0:
			Destory(&plist);
			exit(0);
			break;
		default:
			printf("��������,���������>\n");
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

	//�ж������޻������Ƿ��ཻ
	Find(plist, 8)->next = Find(plist2, 6);
	ret = CheckCross(plist, plist2);
	if (ret == 0)
	{
		printf("���ཻ\n");
	}
	else
	{
		printf("�ཻ\n");
	}

	//���л����ҵ�������ڵ�
	//Find(plist, 8)->next = plist;
	//ret = GetNode(plist, CheckCycle(plist));
	//printf("%d\n", ret->data);
	
	//���л����󻷵ĳ���
	/*Find(plist, 8)->next = plist->next;
    ret = GetCircleLength(CheckCycle(plist));
	printf("%d\n", ret);*/

	//����Ƿ����
	/*Find(plist, 8)->next = plist;
	ret = CheckCycle(plist);
	if (ret == NULL)
	{
		printf("�޻�\n");
	}
	else
	{
		printf("�л�\n");
	}
    */

	//�����ӡ
	/*ShowList(plist);
	PrintReversely(plist);*/
	
	//Լɪ��
	/*Find(plist,8)->next = plist;
	ret = JosephCycle(&plist, 3);
	printf("end:%d\n", ret->data);*/

	//ɾ��������K��
	/*DelKNode(&plist,4);
	ShowList(plist);*/

	//�����м��
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
	printf("����\n");
	PrintComplexList(plist);
    ret = CopyComplexList(plist);
	printf("����\n");
	PrintComplexList(ret);
}

int main()
{
	test3();
	system("pause");
	return 0;
}