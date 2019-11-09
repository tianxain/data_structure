#pragma once
//#ifndef __SEQLIST_H__
//#define __SEQLIST_H__

//#endif

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLDataType;

//// ˳���ľ�̬�洢
//#define N 100
//typedef struct SeqList
//{
//	SLDataType array[N]; // ��������
//	size_t size;// ��Ч���ݵĸ���
//}SeqList;

// ˳���Ķ�̬�洢
typedef struct SeqList
{
	SLDataType* _array; // ָ��̬���ٵ����� 
	size_t _size;	// ��Ч���ݸ��� 
	size_t _capicity;	// �����ռ�Ĵ�С
}SeqList;

// ������ɾ��Ľӿ�
void SeqListInit(SeqList* pSL);
void SeqListDestory(SeqList* pSL);
void SeqListPrint(SeqList* pSL);
void SLCheckCapacity(SeqList* pSL);

void SeqListPushBack(SeqList* pSL, SLDataType x);
void SeqListPopBack(SeqList* pSL);
void SeqListPushFront(SeqList* pSL, SLDataType x);
void SeqListPopFront(SeqList* pSL);

int SeqListFind(SeqList* pSL, SLDataType x);
void SeqListInsert(SeqList* pSL, size_t pos, SLDataType x);
void SeqListErase(SeqList* pSL, size_t pos);
void SeqListRemove(SeqList* pSL, SLDataType x);
void SeqListModify(SeqList* pSL, size_t pos, SLDataType x);
void SeqListPrint(SeqList* pSL);

// ��չ������ʵ��
void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SLDataType x);
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)

