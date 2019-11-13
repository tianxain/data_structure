#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SListPrint(SListNode* pList)
{
	SListNode* cur = pList;
	while (cur)
	{
		printf("%d->",cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void SListInit(SList* plist)
{
	plist->_head->_next=NULL;
}

SListNode* NewSListNode(SLTDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

void SListPushBack(SListNode** ppList, SLTDataType x)
{
	SListNode* newNode = NewSListNode(x);

	if (*ppList == NULL)
	{
		*ppList = newNode;
	}
	else
	{
		SListNode* tail = *ppList;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = newNode;
	}
}
void SListPopBack(SListNode** ppList)
{
	SListNode* prev = NULL;
	SListNode* tail = *ppList;
	//List为空或只有一个结点
	if (tail == NULL || tail->_next == NULL)
	{
		free(tail);
		*ppList = NULL;
	}
	else
	{
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		free(tail);
		tail = NULL;
		prev->_next = NULL;
	}
}
void SListPushFront(SListNode** ppList, SLTDataType x)
{
	SListNode* newNode = NewSListNode(x);
	if (*ppList == NULL)
	{
		*ppList = newNode;
	}
	else
	{
		newNode->_next = *ppList;
		*ppList = newNode;
	}
}
void SListPopFront(SListNode** ppList)
{
	SListNode* pList = *ppList;
	//List为空
	if (pList == NULL)
	{
		return;
	}
	//只有一个结点
	if (pList->_next == NULL)
	{
		*ppList = NULL;
		free(pList);
	}
	else
	{
		*ppList = (*ppList)->_next;
		free(pList);
	}
}

SListNode* SListFind(SList* plist, SLTDataType x)
{

}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{

}

void SListEraseAfter(SListNode* pos)
{

}
void SListRemove(SList* plist, SLTDataType x)
{

}


