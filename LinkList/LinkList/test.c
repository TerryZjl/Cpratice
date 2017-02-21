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
		printf("������ѡ��>");
		scanf("%d", &tmep);
		fflush(stdin);
		switch (tmep)
		{
		case 1:
			printf("������Ҫ��β�����Ԫ��>");
			scanf("%d", &num);
			PushBack(&plist,num);
			break;
		case 2:
			PopBack(&plist);
			break;
		case 3:
			printf("������Ҫ��ͷ�����Ԫ��>");
			scanf("%d", &num);
			PushFront(&plist,num);
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
			Remove(&plist,num);
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
int main()
{
	test();
	return 0;
}