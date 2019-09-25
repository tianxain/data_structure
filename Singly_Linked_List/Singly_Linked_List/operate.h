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

//��e����L�е�i��Ԫ�ص�ֵ
ElemType GetElem(LinkList L,int i,ElemType *e);

//˳���Ĳ���,��L�е�i��λ��֮ǰ�����µ�Ԫ��e
ElemType  ListInsert_L(LinkList *L, int i, ElemType e);


//˳����ɾ��,��L��ɾ����i��Ԫ�أ�����e����
ElemType  ListDelete_L(LinkList *L, int i, ElemType *e);