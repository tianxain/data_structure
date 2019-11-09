#pragma once
//#ifndef __SEQLIST_H__
//#define __SEQLIST_H__

//#endif

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLDataType;

//// 顺序表的静态存储
//#define N 100
//typedef struct SeqList
//{
//	SLDataType array[N]; // 定长数组
//	size_t size;// 有效数据的个数
//}SeqList;

// 顺序表的动态存储
typedef struct SeqList
{
	SLDataType* _array; // 指向动态开辟的数组 
	size_t _size;	// 有效数据个数 
	size_t _capicity;	// 容量空间的大小
}SeqList;

// 基本增删查改接口
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

// 扩展面试题实现
void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SLDataType x);
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)

