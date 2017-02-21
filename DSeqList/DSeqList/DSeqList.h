#ifndef _DSeqList_H__
#define _DSeqList_H__

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#pragma warning(disable:4996)

#define LEN 3
#define ADDLEN 2

typedef	 int DataType;

typedef struct SeqList
{
	DataType *arr;
	DataType count;
	DataType capacity;
}SeqList, *pSeqList;

void InitSeqList(pSeqList pcon);
void PushBack(pSeqList pcon, DataType d);
void Show(pSeqList pcon);
void PopBack(pSeqList pcon);
void PushFront(pSeqList pcon, DataType d);
void PopFront(pSeqList pcon);
int Find(pSeqList pcon, DataType d);
void Remove(pSeqList pcon, DataType d);
void RemoveAll(pSeqList pcon, DataType d);
void Sort(pSeqList pcon);
int BinarySearch(pSeqList pcon,DataType d);

#endif _DSeqList_H__