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

//����������ռ��ʼ����һ������
void InitSpace_SL(SLinkList *space);

//�ӱ��ÿռ��ȡһ�����
int Malloc_SL(SLinkList *Space);

//���±�Ϊk�Ŀ��н�����ӵ�����������
void Free_SL(SLinkList *space,int k);