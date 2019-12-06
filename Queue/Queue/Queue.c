#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

// 初始化队列
void QueueInit(Queue* pQueue)
{
	assert(pQueue);
	pQueue->_front = NULL;
	pQueue->_back = NULL;
}

// 队尾入队列
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

// 队头出队列
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
// 获取队列头部元素
QDataType QueueFront(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->_front->_data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->_back->_data;
}

// 获取队列中有效元素个数
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

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->_front == NULL ? 1 : 0;
}

// 销毁队列
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