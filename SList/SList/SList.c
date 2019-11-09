#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
SListNode* SeqListPushBack(SListNode* list, SLTDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->_data = x;
	newNode->_next = NULL;

	if (list == NULL)
	{
		list = newNode;
		return list;
	}
	else
	{
		SListNode* tail = list;
		while (tail != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = newNode;
		return list;
	}
	
}
SListNode* SeqListPopBack(SListNode* pSL);
SListNode* SeqListPushFront(SListNode* pSL, SLTDataType x);
SListNode* SeqListPopFront(SListNode* pSL);
void SListPrint(SListNode* head)
{

}