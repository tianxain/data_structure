#pragma once
#include<stdio.h>
#define MAXSIZE  10  //������󳤶�
#define ElemType int
#define true 1
#define false 0

typedef struct
{
	ElemType data;
	int cur;  //�α�
}conponent,SLinkList[MAXSIZE];

//��λ����
int LocateElem_SL(SLinkList S, ElemType e);

//����������ռ��ʼ����һ������
void InitSpace_SL(SLinkList *space);

//�ӱ��ÿռ��ȡһ�����
int Malloc_SL(SLinkList *Space);

//���±�Ϊk�Ŀ��н�����ӵ�����������
void Free_SL(SLinkList *space,int k);

//��̬������Ԫ�ظ�����������ͷβ�ڵ�
int Length_SL(SLinkList L);

//��̬������iλ�ò���һ��Ԫ��
int StaticLinkListInsert(SLinkList L, int i, int e);

