#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define OVERFLOW -1
#define OK 1
#define ERROR 0
typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//用e返回L中第i个元素的值
ElemType GetElem(LinkList L,int i,ElemType *e);

//顺序表的插入,在L中第i个位置之前插入新的元素e
ElemType  ListInsert_L(LinkList *L, int i, ElemType e);


//顺序表的删除,在L中删除第i个元素，并用e返回
ElemType  ListDelete_L(LinkList *L, int i, ElemType *e);