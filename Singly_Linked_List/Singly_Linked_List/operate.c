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
	if (!p || j > i)
	{
		return ERROR;
	}
	*e = p->data;
	return OK;
}

//顺序表的插入,在L中第i个位置之前插入新的元素e
ElemType  ListInsert_L(LinkList *L, int i, ElemType e)
{
	LinkList p = *L;
	LinkList s;
	int j = 0;
	while (p&&j < i - 1)  //寻找第i-1个结点
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
	LinkList p = *L;
	LinkList q;
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
	*e = q->data;
	free(p);
	return 0;
}

//从表尾到表头逆向建立单链表
void CreateList_L(LinkList *L, int n)
{
	int i = 0;
	LinkList p;
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;//先建立一个带头节点的单链表
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));//生成新节点
		scanf("%d", &p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

//尾插法创建链表
void CreatList_L1(LinkList *L, int n)
{
	//尾插法创建链表
	   //要将创建的链表返回，所以要传入指针LinkList *L
	int i = 0;
	LinkList p;
	LinkList q;
	q = *L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		q->next = p;
		q = p;
		p->next = NULL;
	}

}

void MergeLsit(LinkList *LA, LinkList *LB, LinkList *LC)
{
	LinkList pa;
	LinkList pb;
	LinkList pc;
	pa = (*LA)->next;
	pb = (*LB)->next;
	LC = pc = LA;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(LB);
}