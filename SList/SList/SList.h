#pragma once
#include<stdio.h>
#include<stdlib.h>
// 无头单向非循环链表增删查改实现 
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data; 
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* pList);
void SListDestory(SList* pList);

void SListPrint(SListNode* pList);
SListNode* NewSListNode(SLTDataType x);

void SListPushBack(SListNode** ppList, SLTDataType x);
void SListPopBack(SListNode** ppList);
void SListPushFront(SListNode** ppList, SLTDataType x);
void SListPopFront(SListNode** ppList);


SListNode* SListFind(SList* plist, SLTDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);

