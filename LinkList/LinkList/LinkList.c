#include"LinkList.h"

void InitLinkList(pList* pplist)
{
	assert(pplist != NULL);
	*pplist = NULL;
}

pNode BuyNode(DataType d)
{
	pNode temp = NULL;
	temp = (pNode)malloc(sizeof(Node));
	temp->data = d;
	temp->next = NULL;
	return temp;
}

void PushBack(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	pNode NewNode = BuyNode(d);
	pNode cur = *pplist;
	if (*pplist == NULL)
	{
		*pplist = NewNode;
		return;
	}
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = NewNode;
	return;
}

void PopBack(pList* pplist)
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	if (*pplist == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	if (cur->next == NULL)
	{
		free(cur);
		*pplist = NULL;
		return;
	}
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

void PushFront(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	pNode NewNode = BuyNode(d);
	pNode cur = *pplist;
	if (cur == NULL)
	{
		cur = NewNode;
		return;
	}
	else
	{
		*pplist = NewNode;
		NewNode->next = cur;
	}
}

void PopFront(pList* pplist)
{
	assert(pplist != NULL);

	pNode cur = *pplist;
	if (cur == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	else
	{
		*pplist = cur->next;
		free(cur);
	}
}

//pNode Find(pList plist, DataType d)
pComplexNode Find(pComplexList plist, DataType d)
{
	pComplexNode cur = plist;
	if (cur == NULL)
	{
		printf("����Ϊ��,");
		return NULL;
	}
	while (cur != NULL)
	{
		if (cur->data == d)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void Remove(pList* pplist, DataType d)
{
	assert(pplist != NULL);

	pNode cur = *pplist;
	pNode del = NULL;
	if (cur == NULL)
	{
		printf("����Ϊ�գ�û��Ҫɾ����Ԫ�أ�\n");
		return;
	}
	if (cur->data == d)
	{
		*pplist = cur->next;
		free(cur);
		printf("��ɾ����\n");
		return;
	}
	while (cur->next != NULL)
	{
		del = cur->next;
		if (del->data == d)
		{
			cur->next = del->next;
			free(del);
			printf("��ɾ����\n");
			return;
		}
		cur = cur->next;
	}
	printf("û��Ҫɾ����Ԫ��\n");
	return;
}

void RemoveAll(pList* pplist, DataType d)
{
	assert(pplist != NULL);

	pNode cur = *pplist;
	pNode del = NULL;
	if (cur == NULL)
	{
		printf("����Ϊ�գ�û��Ҫɾ����Ԫ�أ�\n");
		return;
	}

	while (cur->data == d)
	{
		*pplist = cur->next;
		free(cur);
		cur = *pplist;
		if (cur == NULL)
		{
			printf("��ɾ����\n");
			return;
		}
	}

	while (cur->next != NULL)
	{
		while (cur->next->data == d)
		{
			del = cur->next;
			cur->next = del->next;
			free(del);
			if (cur->next == NULL)
			{
				printf("��ɾ����\n");
				return;
			}
		}
		cur = cur->next;
	}
	printf("��ɾ����\n");
	return;
}


void Insert(pList *pplist, pNode pos, DataType d)
{
	assert(pplist != NULL);

	pNode NewNode = BuyNode(d);
	NewNode->next = pos->next;
	pos->next = NewNode;
	printf("����ɹ�\n");
	return;
}

void Erase(pList *pplist, pNode pos)
{
	assert(pplist != NULL);

	pNode del = pos->next;
	pos->next = pos->next->next;
	free(del);
	printf("ɾ���ɹ�\n");
	return;
}

//void Insert(pList *pplist, int pos, DataType d)
//{
//	assert(pplist != NULL);
//	int j = 0;
//	pNode cur = *pplist;
//	while (cur != NULL&&j < pos-1)
//	{
//		j++;
//		cur = cur->next;
//	}
//	if (j>pos-1||cur==NULL)
//	{
//		printf("��������\n");
//		return;
//	}
//	pNode NewNode = BuyNode(d);
//	NewNode->next = cur->next;
//	cur->next = NewNode;
//	printf("����ɹ�\n");
//	return;
//}
//
//void Erase(pList *pplist, int pos)
//{
//	assert(pplist != NULL);
//
//	int i = 0;
//	pNode cur = *pplist;
//	pNode del = NULL;
//	while (cur->next != NULL&&i < pos - 1)
//	{
//		i++;
//		cur = cur->next;
//	}
//	if (i>pos - 1 || (cur->next == NULL))    //1  2  3   4
//	{
//		printf("��������\n");
//		return;
//	}
//	del = cur->next;
//	cur->next = cur->next->next;
//	free(del);
//	printf("��ɾ��\n");
//	return;
//}

void ShowList(pList plist)
{
	int i = 0;
	pNode cur = plist;
	if (cur == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	while (i <= GetLinkListLen(plist))
	{
		i++;
		printf("%d  ", i);
	}
	printf("\n");
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void Destory(pList* pplist)
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	while (cur != NULL)
	{
		*pplist = cur->next;
		free(cur);
		cur = *pplist;
	}
}

int GetLinkListLen(pList plist)
{
	int count = 0;
	pNode cur = plist;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;

	}
	return count;
}

//ɾ����ͷ������ķ�β���
void EraseNotTail(pNode pos)
{
	pNode del = pos->next;
	pos->data = pos->next->data;
	pos->next = pos->next->next;
	free(del);
}
//��ת
void ReverseList(pList* pplist)
{
	assert(pplist);

	pNode tmp = NULL;
	pList newlist = NULL;
	pNode cur = *pplist;
	if ((*pplist == NULL) || ((*pplist)->next == NULL))
	{
		return;
	}
	while (cur != NULL)
	{
		tmp = cur;
		cur = cur->next;       //���ﲻ��д�����棬��д������tmp->next = NULL; �Ͱ�cur��next�óɿ���
		tmp->next = newlist;
		newlist = tmp;
	}
	*pplist = newlist;
	return;
}

void BubbleSort(pList* pplist)
{
	assert(pplist);
	pNode cur = *pplist;
	pNode tail = NULL;
	pNode tmp = *pplist;
	DataType a = 0;
	while (cur->next != NULL)
	{
		tmp = *pplist;
		tail = cur;
		while (tail->next != NULL)
		{
			if (tmp->data > tmp->next->data)
			{
				a = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = a;
			}
			tmp = tmp->next;
			tail = tail->next;
		}
		cur = cur->next;
	}
}

void InsertFrontNode(pNode pos, DataType d)    //�嵽��ǰλ�õĺ��棬Ȼ���ڽ���ֵ
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->data = d;
	newNode->next = NULL;
	newNode->next = pos->next;
	pos->next = newNode;
	DataType tmp = pos->data;
	pos->data = newNode->data;
	newNode->data = tmp;
	return;
}

pList Merge(pList list1, pList list2)      //�ǵݹ�
{
	pList NewList = NULL;
	pNode tail = NULL;  //���˹�
	if (list1 == list2)
	{
		return list1;
	}
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}
	if (list1->data <= list2->data)
	{
		NewList = list1;
		list1 = list1->next;
	}
	else
	{
		NewList = list2;
		list2 = list2->next;
	}
	tail = NewList;
	while ((list1 != NULL) && (list2 != NULL))
	{
		if (list1->data <= list2->data)
		{
			tail->next = list1;
			tail = list1;
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			tail = list2;
			list2 = list2->next;
		}
	}
	if (list1 == NULL)
	{
		tail->next = list2;
	}
	else
	{
		tail->next = list1;
	}
	return NewList;
}


pList Merge2(pList list1, pList list2)      //�ݹ�ϲ���������
{
	pList NewList = NULL;
	pNode tail = NULL;  //���˹�
	if (list1 == list2)
	{
		return list1;
	}
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}
	if (list1->data <= list2->data)
	{
		NewList = list1;
		NewList->next = Merge2(list1->next, list2);
	}
	else
	{
		NewList = list2;
		NewList->next = Merge2(list1, list2->next);
	}

	return NewList;
}

pNode FindMidNode(pList plist)
{
	pNode fast = plist;
	pNode slow = plist;

	while (fast != NULL&&fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

void DelKNode(pList* pplist, int k)
{
	assert(pplist);

	if (k <= 1 || k > GetLinkListLen(*pplist))
	{
		printf("��������\n");
		return;
	}
	pNode fast = *pplist;
	pNode slow = *pplist;
	pNode del = NULL;
	while (fast->next != NULL)
	{
		--k;
		if (k <= 0)
		{
			slow = slow->next;
		}
		fast = fast->next;
	}
	del = slow->next;
	slow->data = slow->next->data;
	slow->next = slow->next->next;
	free(del);
}

pNode JosephCycle(pList* pplist, int num)
{
	int i = 0;
	pNode del = NULL;
	pNode cur = *pplist;
	assert(pplist);
	while (1)
	{
		if (cur->next == cur)
		{
			return cur;
		}
		for (i = 0; i < num-1; i++)
		{
			cur = cur->next;
		}
		del = cur->next;
		printf("%d\n", cur->data);
		cur->data = cur->next->data;
		cur->next = cur->next->next;
		free(del);
	}
}

void PrintReversely(pList plist)
{
	pNode cur = plist;

	if (cur->next)
	{
		PrintReversely(cur->next);
	}
	printf("%d->", cur->data);
}

//��������Ƿ����
pNode CheckCycle(pList plist)
{
	pNode fast = plist;
	pNode slow = plist;
    
	while (fast != NULL&&fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return slow;
		}
	}
	return NULL;
}
//���л��� �󻷵ĳ���
int GetCircleLength(pList plist)
{
	pNode cur = plist;
	int count = 0;
	while(1)
	{
		cur = cur->next;
		count++;
		if (cur == plist)
		{
			return count;
		}
	}
}

pNode GetNode(pList plist, pNode meetNode)
{
	pNode cur = plist;
	while (cur != meetNode)
	{
		cur = cur->next;
		meetNode = meetNode->next;
	}
	return cur;
}

int CheckCross(pList list1, pList list2)
{
	if (list1 == NULL || list2 == NULL)
	{
		return 0;
	}
	while (list1->next != NULL)
	{
		list1 = list1->next;
	}
	while (list2->next != NULL)
	{
		list2 = list2->next;
	}
	if (list1 == list2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void PrintComplexList(pComplexList plist)
{
	pComplexNode cur = plist;
	while (cur->next)
	{
		printf("[%d]-next>[%d]-randmo>[%d]\n", cur->data, cur->next->data, cur->randmo->data);
		cur = cur->next;
	}
	printf("[%d]-next>NULL-randmo>[%d]\n", cur->data, cur->randmo->data);
	return;
}

//pComplexNode CopyComplexList(pComplexNode* pplist)
//{
//	assert(pplist);
//	pComplexNode newNode = NULL;
//	pComplexNode cur = *pplist;
//	pComplexNode tail = *pplist;
//	pComplexList list1 = *pplist;
//	pComplexList list2 = *pplist;
//
//	//����ԭʼ����pNode,���ں���
//	while (tail)
//	{
//		newNode = (pComplexNode)malloc(sizeof(ComplexNode));
//		newNode->data = tail->data;
//		newNode->next = tail->next;
//		tail->next = newNode;
//		tail = tail->next->next;
//	}
//	//����randmoָ��
//	tail = *pplist;
//	while (tail)
//	{
//		tail->next->randmo = tail->randmo->next;
//		tail = tail->next->next;
//	}
//	
//	//������������
//	tail = (*pplist)->next;
//	list2 = tail;
//	while(tail->next)
//	{
//		list1->next = tail->next;
//		list1 = list1->next;
//		tail->next = list1->next;
//		tail = tail->next;
//	}
//	list1->next = NULL;
//	return list2;
//}
pComplexNode CopyComplexList(pComplexNode plist)
{
	pComplexNode newNode = NULL;
	pComplexNode cur = plist;
	pComplexNode tail = plist;
	pComplexList list1 = plist;
	pComplexList list2 = plist;

	//����ԭʼ����pNode,���ں���
	while (tail)
	{
		newNode = (pComplexNode)malloc(sizeof(ComplexNode));
		newNode->data = tail->data;
		newNode->next = tail->next;
		tail->next = newNode;
		tail = tail->next->next;
	}
	//����randmoָ��
	tail = plist;
	while (tail)
	{
		tail->next->randmo = tail->randmo->next;
		tail = tail->next->next;
	}

	//������������
	tail = plist->next;
	list2 = tail;
	while (tail->next)
	{
		list1->next = tail->next;
		list1 = list1->next;
		tail->next = list1->next;
		tail = tail->next;
	}
	list1->next = NULL;
	return list2;
}
