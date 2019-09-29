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
		space[MAXSIZE - 1]->cur = i + 1;

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