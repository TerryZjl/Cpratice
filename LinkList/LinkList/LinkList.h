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



#endif __LinkList_H__