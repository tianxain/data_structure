#pragma once
#include<stdio.h>
#define MAXSIZE  10  //链表最大长度
#define ElemType int
#define true 1
#define false 0

typedef struct
{
	ElemType data;
	int cur;  //游标
}conponent,SLinkList[MAXSIZE];

//定位函数
int LocateElem_SL(SLinkList S, ElemType e);

//将整个数组空间初始化成一个链表
void InitSpace_SL(SLinkList *space);

//从备用空间获取一个结点
int Malloc_SL(SLinkList *Space);

//将下表为k的空闲结点链接到备用链表上
void Free_SL(SLinkList *space,int k);

//求静态链表中元素个数，不包括头尾节点
int Length_SL(SLinkList L);

//静态链表中i位置插入一个元素
int StaticLinkListInsert(SLinkList L, int i, int e);

