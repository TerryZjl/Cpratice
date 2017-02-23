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

typedef struct ComplexNode
{
	DataType data;
	struct ComplexNode* next;
	struct ComplexNode* randmo;
}ComplexNode, *pComplexNode, *pComplexList;

void InitLinkList(pList* pplist);
void PushBack(pList* pplist, DataType d);
void ShowList(pList plist);
void Destory(pList* pplist);
void PopBack(pList* pplist);
void PushFront(pList* pplist, DataType d);
void PopFront(pList* pplist);
//pNode Find(pList plist, DataType d);
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
pList Merge2(pList list1, pList list2);
//链表冒泡排序
void BubbleSort(pList* pplist);
//查找链表中间节点
pNode FindMidNode(pList plist);
//删除单链表的倒数第K个节点（k>1&&k<链表长度）时间复杂度为O(N);
void DelKNode(pList* pplist, int k);
//约瑟夫环问题
pNode JosephCycle(pList* pplist, int num);
//检测链表是否带环
pNode CheckCycle(pList plist);
//逆序打印链表
void PrintReversely(pList plist);
//若有环，求环的长度
int GetCircleLength(pList plist);
//若有环，找到环的入口点
pNode GetNode(pList plist, pNode meetNode);
//判断两条无环链表是否相交
int CheckCross(pList list1, pList list2);


pComplexNode Find(pComplexList plist, DataType d);
void PrintComplexList(pComplexList plist);
pComplexNode CopyComplexList(pComplexNode plist);

#endif __LinkList_H__