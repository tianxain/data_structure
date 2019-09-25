#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int ElemType;
#define INFEASIBLE -1
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define LIST_INT_SIZE 100 //线性表存储空间初始分配量
#define LISTINCREAMENT 10  //线性表存储空间分配增量


typedef struct Sqlist {
	ElemType* elem;  //存储空间基址
	int length;  //当前长度
	int listsize;//当前分配的存储容量(以sizeof(int)为单位)
}SqList;

//构造一个空的线性表L
int  InitList_Sq(SqList *L);

//线性表输入元素
int Input_Sq(SqList *L, int n);

//输出线性表
int Output_Sq(SqList *L, int i);

//顺序表的插入,在L中第i个位置之前插入新的元素e
int ListInsert_Sq(SqList *L, int i, ElemType e);

//顺序表的删除,在L中删除第i个元素，并用e返回
int ListDelete_Sq(SqList *L, int i, ElemType *e);

//合并LA，LB，结果保存到A
void Union(SqList *LA, SqList LB);

//归并LA，LB为一个新表LC,仍按非值有序递减
void MergList(SqList LA, SqList LB, SqList *LC);

//判定是否为空表ListEmpty(L)
int ListEmpty(SqList *L);

//求线性表的长度ListLength(L)
int ListLength(SqList *L);

//求某个数据元素值GetElem(L,i,e)
int GetElem(SqList L, int i, ElemType *e);

//按元素值查找LocateElem(L,e)
int LocateElem(SqList *L, ElemType e);