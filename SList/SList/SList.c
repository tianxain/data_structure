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

SListNode* SListFind(SListNode* pList, SLTDataType x)
{
	SListNode* cur = pList;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}


void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* next = pos->_next;
	SListNode* newNode = NewSListNode(x);
	pos->_next = newNode;
	newNode->_next = next;
}
void SListInsertBefore(SListNode* pos, SLTDataType x)
{

}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* next = pos->_next;
	if (next != NULL)
	{
        SListNode* nextnext = next->_next;
	    free(next);
	    pos->_next = nextnext;
	}
}
void SListEraseBefore(SListNode* pos)
{

}

void SListRemove(SListNode* pList, SLTDataType x)
{

}




