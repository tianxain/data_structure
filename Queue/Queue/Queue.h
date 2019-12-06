#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

// 链式结构：表示队列
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// 队列的结构
typedef struct Queue
{
	QNode* _front;
	QNode* _back;
}Queue;

// 初始化队列
void QueueInit(Queue* pQueue);
// 销毁队列
void QueueDestroy(Queue* pQueue);

// 队尾入队列
void QueuePush(Queue* pQueue, QDataType x);
// 队头出队列
void QueuePop(Queue* pQueue);

// 获取队列头部元素
QDataType QueueFront(Queue* pQueue);
// 获取队列队尾元素
QDataType QueueBack(Queue* pQueue);

// 获取队列中有效元素个数
int QueueSize(Queue* pQueue);

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* pQueue);
