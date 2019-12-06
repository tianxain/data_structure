#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

// ��ʼ������
void QueueInit(Queue* pQueue)
{
	assert(pQueue);
	pQueue->_front = NULL;
	pQueue->_back = NULL;
}

// ��β�����
void QueuePush(Queue* pQueue, QDataType x)
{
	assert(pQueue);

	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->_data = x;
	if (pQueue->_back==NULL)
	{
		pQueue->_front = pQueue->_back = newNode;
	}
	else
	{
		pQueue->_back ->_pNext= newNode;
		pQueue->_back = newNode;
	}
}

// ��ͷ������
void QueuePop(Queue* pQueue)
{
	assert(pQueue);

	QNode* next = pQueue->_front->_pNext;
	if (next == NULL)
	{
		pQueue->_back = pQueue->_front = NULL;
		return;
	}
	free(pQueue->_front);
	pQueue->_front = next;
}
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->_front->_data;
}

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->_back->_data;
}

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pQueue)
{
	assert(pQueue);
	QNode* cur = pQueue->_front;
	size_t n = 0;
	while (cur)
	{
		n++;
		cur = cur->_pNext;
	}
	return n;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->_front == NULL ? 1 : 0;
}

// ���ٶ���
void QueueDestroy(Queue* pQueue)
{
	QNode* cur = pQueue->_front;
	while (cur)
	{
		QNode* next = cur->_pNext;
		free(cur);
		cur = next;
	}
}