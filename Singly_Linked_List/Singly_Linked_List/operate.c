#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"

//��e����L�е�i��Ԫ�ص�ֵ
int GetElem(LinkList L, int i, ElemType *e)
{
	LNode *p;
	int j = 1; //������
	p = L->next; //��ʼ����pָ���һ�����
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

//˳���Ĳ���,��L�е�i��λ��֮ǰ�����µ�Ԫ��e
int  ListInsert_L(LinkList *L, int i, ElemType e)
{
	LinkList p = *L;
	LinkList s;
	int j = 0;
	while (p&&j < i - 1)  //Ѱ�ҵ�i-1�����
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
int  ListDelete_L(LinkList *L, int i, ElemType *e)
{
	LinkList p = *L;
	LinkList q;
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
	*e = q->data;
	free(p);
	return 0;
}

//�ӱ�β����ͷ������������
void CreateList_L(LinkList *L, int n)
{
	int i = 0;
	LinkList p;
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;//�Ƚ���һ����ͷ�ڵ�ĵ�����
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));//�����½ڵ�
		scanf("%d", &p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

//β�巨��������
void CreatList_L1(LinkList *L, int n)
{
	//β�巨��������
	   //Ҫ�������������أ�����Ҫ����ָ��LinkList *L
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

void MergeLsit(LinkList LA, LinkList LB, LinkList *LC)
{
	LinkList pa;
	LinkList pb;
	LinkList pc;
	pa = LA->next;
	pb = LB->next;
	*LC = pc = LA;
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

//ͷ�巨��������
void CreatList_L2(LinkList *L, int n)
{
	//ͷ�巨��������
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;         //ͷ�巨һ���������
	LinkList s;
	for (int i = 0; i < n; i++)
	{
		s = (LinkList)malloc(sizeof(LNode));//�����½ڵ�
		scanf("%d", &s->data);
		s->next = (*L)->next;   //���¿��ٵĽڵ�鵽ͷ�ڵ����
		(*L)->next = s;
	}
}


//��ѯ�����i��λ�õ�Ԫ�أ���������ֵ��
int GetElem_L(LinkList L, int i, ElemType *e)
{
	//LΪ��ͷ�ڵ�ĵ������ͷָ��
		//��i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
	LinkList p = L;   //��ʼ����pָ���1���ڵ�
	int j = 0;        //������
	while (p && j < i) //˳ʱ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)   //��i��Ԫ�ز�����
		return ERROR;
	*e = p->data;      //ȡ��i��Ԫ��
	return OK;
}//GetElem_L