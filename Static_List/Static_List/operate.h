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