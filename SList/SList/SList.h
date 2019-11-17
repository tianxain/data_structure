#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// ��ͷ�����ѭ��������ɾ���ʵ�� 
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data; 
	struct SListNode* _next;
}SListNode;


void SListPrint(SListNode* pList);
SListNode* NewSListNode(SLTDataType x);

void SListPushBack(SListNode** ppList, SLTDataType x);
void SListPopBack(SListNode** ppList);
void SListPushFront(SListNode** ppList, SLTDataType x);
void SListPopFront(SListNode** ppList);
SListNode* SListFind(SListNode* pList, SLTDataType x);
void SListInsertAfter(SListNode* pos, SLTDataType x);
void SListInsertBefore(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);
void SListEraseBefore(SListNode* pos);
void SListRemove(SListNode* plist, SLTDataType x);

