#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"

//��λ�������ҵ�������ţ����򷵻�0
int LocateElem_SL(SLinkList S, ElemType e)
{
	int i = 0;
	i = S[0].cur; //iָʾ���е�һ�����
	while (i&&S[i].data != e) //�ڱ���˳������
	{
		i = S[i].cur;
	}
	return i;
}

//����������ռ��ʼ����һ������
void InitSpace_SL(SLinkList *space)
{
	//space[0].curΪͷָ�� 0��ʾ��ָ��
	int i = 0;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i]->cur = i + 1;
		space[MAXSIZE - 1]->cur = 0;

}

//�ӱ��ÿռ��ȡһ�����
int Malloc_SL(SLinkList *space)
{
	//�����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0
	int i = 0;
	i = space[0]->cur;
	if (space[0]->cur)
	{
		space[0]->cur = space[i]->cur;
	}
	return i;
}

//���±�Ϊk�Ŀ��н�����ӵ�����������
void Free_SL(SLinkList *space, int k)
{
	space[k]->cur = space[0]->cur;
	space[0]->cur = k;
}

//��̬������Ԫ�ظ�����������ͷβ�ڵ�
int Length_SL(SLinkList L)
{
	int i = 0;
	int j = 0;
	i = L[MAXSIZE - 1].cur;
	while (i)
	{
		j++;
		i = L[i].cur;
	}
	return j;
}

//��̬������iλ�ò���һ��Ԫ��
int StaticLinkListInsert(SLinkList L, int i, int e)
{
	//�жϲ�����Ƿ����
	if (i<1 || i>Length_SL(L) + 1)
	{
		return false;
	}
	int j = Malloc(L);
	int k = MAXSIZE - 1;
	if (j)
	{
		for (int m = 1; m <= j - 1; m++)
		{
			k = L[k].cur;
		}
		L[j].data = e;
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return true;
	}
	return false;

}

int StaticLinkListDelete(SLinkList L, int i, int *key)
{
	if (i < 1 || i >= StaticLinkListLength(L))
	{
		return false;
	}
	int k = MAXSIZE - 1;
	for (int l = 1; l <= i - 1; l++)
	{
		k = L[k].cur;
	}
	int j = L[k].cur;
	*key = L[j].data;
	L[k].cur = L[j].cur;
	//Free(L, j);
	return true;
}

//����
void StaticLinkListTraverse(SLinkList L)
{
	int k = MAXSIZE - 1;
	while (L[k].cur)
	{
		k = L[k].cur;
		printf("%d ", L[k].data);
	}
	printf("\n");
}
