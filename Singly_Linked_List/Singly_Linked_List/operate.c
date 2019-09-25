#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"

//��e����L�е�i��Ԫ�ص�ֵ
ElemType GetElem(LinkList L, int i, ElemType *e)
{
	LNode *p;
	int j = 1; //������
	p = L->next; //��ʼ����pָ���һ�����
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}
	if (!p||j>i)
	{
		return ERROR;
	}
	*e = p->data;
	return OK;
}

//˳���Ĳ���,��L�е�i��λ��֮ǰ�����µ�Ԫ��e
ElemType  ListInsert_L(LinkList *L, int i, ElemType e)
{
	LNode *p = L;
	LNode *s;
	int j = 0;
	while (p&&j<i-1)  //Ѱ�ҵ�i-1�����
	{
		p = p->next;
		++j;
	}
	if (!p || j > i + 1) 
	{
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(LNode));//�����½��
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//˳����ɾ��,��L��ɾ����i��Ԫ�أ�����e����
ElemType  ListDelete_L(LinkList *L, int i, ElemType *e)
{
	LNode *p = L;
	LNode *q;
	int j = 0;
	while (p->next&&j < i - 1)  //Ѱ�ҵ�i�����
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
		return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(p);
}