#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"
// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	return head;
}

//����һ���½��
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
	newHead->_data = x;
	return newHead;
}

// ˫����������
void ListDestory(ListNode* pHead)
{

}

// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->_next;
	printf("HEAD->");
	while (cur != pHead)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* newNode = BuyListNode(x);
	ListNode* tail = pHead->_prev;
	tail->_next = newNode;
	newNode->_prev = tail;
	newNode->_next = pHead;
	pHead->_prev = newNode;
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	ListNode* tail = pHead->_prev;
	ListNode* tailPrev = tail->_prev;
	tailPrev->_next = pHead;
	pHead->_prev = tailPrev;
	free(tail);

	//ListNode* tail = pHead->_prev;
	//pHead->_prev = tail->_prev;
	//tail->_prev->_next = pHead;
	//free(tail);
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* newNode = BuyListNode(x);
	ListNode* first = pHead->_next;
	pHead->_next = newNode;
	newNode->_prev = pHead;
	newNode->_next = first;
	first->_prev = newNode;
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	ListNode* first = pHead->_next;
	ListNode* firstNext = first->_next;
	pHead->_next = firstNext;
	firstNext->_prev = pHead;
	free(first);
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newNode = BuyListNode(x);
	prev->_next = newNode;
	newNode->_prev = prev;
	newNode->_next = pos;
	pos->_prev = newNode;

}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	
	prev->_next = next;
	next->_prev = prev;
	free(pos);
}
