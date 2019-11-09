#pragma once
#include<stdio.h>
#include<stdlib.h>
// 1、无头单向非循环链表增删查改实现 
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

void SListInit(SList* plist);
void SListDestory(SList* plist);

SListNode* SeqListPushBack(SListNode* pSL, SLTDataType x);
SListNode* SeqListPopBack(SListNode* pSL);
SListNode* SeqListPushFront(SListNode* pSL, SLTDataType x);
SListNode* SeqListPopFront(SListNode* pSL);


SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x); 
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SListNode* plist);
void TestSList();