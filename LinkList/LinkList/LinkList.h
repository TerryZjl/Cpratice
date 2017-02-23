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

//ɾ����ͷ������ķ�β���
void EraseNotTail(pNode pos);
//��ת
void ReverseList(pList* pplist);
//�ڵ�ǰ���ǰ����һ������d
void InsertFrontNode(pNode pos, DataType d);
//�ϲ���������
pList Merge(pList list1, pList list2);
pList Merge2(pList list1, pList list2);
//����ð������
void BubbleSort(pList* pplist);
//���������м�ڵ�
pNode FindMidNode(pList plist);
//ɾ��������ĵ�����K���ڵ㣨k>1&&k<�����ȣ�ʱ�临�Ӷ�ΪO(N);
void DelKNode(pList* pplist, int k);
//Լɪ������
pNode JosephCycle(pList* pplist, int num);
//��������Ƿ����
pNode CheckCycle(pList plist);
//�����ӡ����
void PrintReversely(pList plist);
//���л����󻷵ĳ���
int GetCircleLength(pList plist);
//���л����ҵ�������ڵ�
pNode GetNode(pList plist, pNode meetNode);
//�ж������޻������Ƿ��ཻ
int CheckCross(pList list1, pList list2);


pComplexNode Find(pComplexList plist, DataType d);
void PrintComplexList(pComplexList plist);
pComplexNode CopyComplexList(pComplexNode plist);

#endif __LinkList_H__