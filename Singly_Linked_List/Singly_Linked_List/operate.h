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
int GetElem(LinkList L,int i,ElemType *e);

//顺序表的插入,在L中第i个位置之前插入新的元素e
int  ListInsert_L(LinkList *L, int i, ElemType e);


//顺序表的删除,在L中删除第i个元素，并用e返回
int  ListDelete_L(LinkList *L, int i, ElemType *e);

//从表尾到表头逆向建立单链表
void CreateList_L(LinkList *L,int n);

//头插法创建链表
void CreatList_L2(LinkList *L, int n);

//尾插法创建链表
void CreatList_L1(LinkList *L, int n);

void MergeLsit(LinkList LA, LinkList LB, LinkList *LC);

//查询链表第i个位置的元素，并返回其值：
int GetElem_L(LinkList L, int i, ElemType *e);