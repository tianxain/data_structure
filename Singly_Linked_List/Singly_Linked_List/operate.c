#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"

//用e返回L中第i个元素的值
ElemType GetElem(LinkList L, int i, ElemType *e)
{
	LNode *p;
	int j = 1; //计数器
	p = L->next; //初始化，p指向第一个结点
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

//顺序表的插入,在L中第i个位置之前插入新的元素e
ElemType  ListInsert_L(LinkList *L, int i, ElemType e)
{
	LNode *p = L;
	LNode *s;
	int j = 0;
	while (p&&j<i-1)  //寻找第i-1个结点
	{
		p = p->next;
		++j;
	}
	if (!p || j > i + 1) 
	{
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(LNode));//生成新结点
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//顺序表的删除,在L中删除第i个元素，并用e返回
ElemType  ListDelete_L(LinkList *L, int i, ElemType *e)
{
	LNode *p = L;
	LNode *q;
	int j = 0;
	while (p->next&&j < i - 1)  //寻找第i个结点
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