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
		printf("链表为空\n");
		return ;
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
		printf("链表为空\n");
		return;
	}
	else
	{
		*pplist = cur->next;
		free(cur);
	}
}

pNode Find(pList plist, DataType d)
{
	pNode cur = plist;
	if (cur == NULL)
	{
		printf("链表为空,");
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
		printf("链表为空，没有要删除的元素！\n");
		return ;
	}
	if (cur->data == d)
	{
		*pplist = cur->next;
		free(cur);
		printf("已删除！\n");
		return;
	}
	while (cur->next != NULL)
	{
		del = cur->next;
		if (del->data == d)
		{
			cur->next= del->next;
			free(del);
			printf("已删除！\n");
			return ;
		}
		cur = cur->next;
	}
	printf("没有要删除的元素\n");
	return;
}

void RemoveAll(pList* pplist, DataType d)
{
	assert(pplist != NULL);

	pNode cur = *pplist;
	pNode del = NULL;
	if (cur == NULL)
	{
		printf("链表为空，没有要删除的元素！\n");
		return;
	}

		while (cur->data == d)
		{
			*pplist = cur->next;
			free(cur);
			cur = *pplist;
			if (cur == NULL)
			{
				printf("已删除！\n");
				return;
			}
		}
	
		while (cur->next != NULL)
		{
			while(cur->next->data == d)
			{ 
				del = cur->next;
				cur->next = del->next;
				free(del);
				if (cur->next == NULL)
				{
					printf("已删除！\n");
					return;
				}
			}
			cur = cur->next;
		}
		printf("已删除！\n");
		return;
}


void Insert(pList *pplist, pNode pos, DataType d)
{
	assert(pplist != NULL);

	pNode NewNode = BuyNode(d);
	NewNode->next = pos->next;
	pos->next = NewNode;
	printf("插入成功\n");
	return;
}

void Erase(pList *pplist, pNode pos)
{
	assert(pplist != NULL);

	pNode del = pos->next;
	pos->next = pos->next->next;
	free(del);
	printf("删除成功\n");
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
//		printf("输入有误\n");
//		return;
//	}
//	pNode NewNode = BuyNode(d);
//	NewNode->next = cur->next;
//	cur->next = NewNode;
//	printf("插入成功\n");
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
//		printf("输入有误\n");
//		return;
//	}
//	del = cur->next;
//	cur->next = cur->next->next;
//	free(del);
//	printf("已删除\n");
//	return;
//}

void ShowList(pList plist)
{
	int i = 0;
	pNode cur = plist;
	if (cur == NULL)
	{
		printf("链表为空\n");
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