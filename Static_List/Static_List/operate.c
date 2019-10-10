#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"

//定位函数，找到返回序号，否则返回0
int LocateElem_SL(SLinkList S, ElemType e)
{
	int i = 0;
	i = S[0].cur; //i指示表中第一个结点
	while (i&&S[i].data != e) //在表中顺链查找
	{
		i = S[i].cur;
	}
	return i;
}

//将整个数组空间初始化成一个链表
void InitSpace_SL(SLinkList *space)
{
	//space[0].cur为头指针 0表示空指针
	int i = 0;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i]->cur = i + 1;
		space[MAXSIZE - 1]->cur = 0;

}

//从备用空间获取一个结点
int Malloc_SL(SLinkList *space)
{
	//若备用空间链表非空，则返回分配的结点下标，否则返回0
	int i = 0;
	i = space[0]->cur;
	if (space[0]->cur)
	{
		space[0]->cur = space[i]->cur;
	}
	return i;
}

//将下表为k的空闲结点链接到备用链表上
void Free_SL(SLinkList *space, int k)
{
	space[k]->cur = space[0]->cur;
	space[0]->cur = k;
}

//求静态链表中元素个数，不包括头尾节点
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

//静态链表中i位置插入一个元素
int StaticLinkListInsert(SLinkList L, int i, int e)
{
	//判断插入点是否合理
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

//遍历
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
