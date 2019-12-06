#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

// ��ʽ�ṹ����ʾ����
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// ���еĽṹ
typedef struct Queue
{
	QNode* _front;
	QNode* _back;
}Queue;

// ��ʼ������
void QueueInit(Queue* pQueue);
// ���ٶ���
void QueueDestroy(Queue* pQueue);

// ��β�����
void QueuePush(Queue* pQueue, QDataType x);
// ��ͷ������
void QueuePop(Queue* pQueue);

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pQueue);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pQueue);

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pQueue);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* pQueue);
