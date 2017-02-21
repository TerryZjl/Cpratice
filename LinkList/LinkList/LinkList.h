#ifndef __LinkList_H__
#define __LinkList_H__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, *pList;


void InitLinkList(pList* pplist);
void PushBack(pList* pplist, DataType d);
void ShowList(pList plist);
void Destory(pList* pplist);
void PopBack(pList* pplist);
void PushFront(pList* pplist, DataType d);
void PopFront(pList* pplist);
pNode Find(pList plist, DataType d);
void Remove(pList* pplist, DataType d);
void RemoveAll(pList* pplist, DataType d);
void Insert(pList *pplist, pNode pos, DataType d);
void Erase(pList *pplist, pNode pos);
int GetLinkListLen(pList plist);

//void Insert(pList *pplist, int pos, DataType d);
//void Erase(pList *pplist, int pos);

//删除无头单链表的非尾结点
void EraseNotTail(pNode pos);
//翻转
void ReverseList(pList* pplist);
//在当前结点前插入一个数据d
void InsertFrontNode(pNode pos, DataType d);
//合并两个链表
pList Merge(pList list1, pList list2);
//链表冒泡排序
void BubbleSort(pList* pplist);

#endif __LinkList_H__