#pragma once
#include<stdio.h>
#define MAXSIZE  100  //链表最大长度
#define ElemType int
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