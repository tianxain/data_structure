#pragma once
#include<stdio.h>
#define MAXSIZE  100  //������󳤶�
#define ElemType int
typedef struct
{
	ElemType data;
	int cur;  //�α�
}conponent,SLinkList[MAXSIZE];

//��λ����
int LocateElem_SL(SLinkList S, ElemType e);