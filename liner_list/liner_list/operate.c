#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"
//构造一个空的线性表L
int  InitList_Sq(SqList *L)
{
	L->elem = (ElemType *)malloc(LIST_INT_SIZE * sizeof(ElemType));
	if (!L->elem)  //存储分配失败
	{
		exit(OVERFLOW);
	}
	L->length = 0; //空表长度为0
	L->listsize = LIST_INT_SIZE; ///初始存储容量
	return OK;
}

//线性表输入元素
int Input_Sq(SqList *L, int n)
{
	int i;
	int *newbase;
	if (n < 0)
		return ERROR;
	if (n >= L->listsize)//超过当前存储空间
	{
		newbase = (ElemType *)malloc(LIST_INT_SIZE * sizeof(ElemType));
		if (!newbase)//存储分配失败
		{
			exit(OVERFLOW);
		}
		L->elem = newbase;//新基址
		L->listsize += LISTINCREAMENT;//增加存储容量
	}
	printf("请输入元素：\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &L->elem[i]);
		L->length++;
	}
	return OK;
}

//输出线性表
int Output_Sq(SqList *L, int i)
{
	int j;
	printf("线性表为：\n");
	for (j = 0; j < i; j++)
	{
		printf("%d\t", L->elem[j]);
	}
	return OK;
}


int ListInsert_Sq(SqList *L, int i, ElemType e)
{
	ElemType *newbase = 0;
	ElemType *q = 0;
	ElemType *p = 0;
	//i的合法值为1<=i&&i<=ListLength-Sq(L)-1
	if (i<1 || i>L->length - 1) //i输入不合法
		return ERROR;
	if (L->length >= L->listsize)//当前存储空间已满，增加分配
	{
		newbase = (ElemType *)realloc(L->elem,
			(LISTINCREAMENT + L->listsize) * sizeof(ElemType));
		if (!newbase)//存储分配失败
		{
			exit(OVERFLOW);
		}
		L->elem = newbase;//新基址
		L->listsize += LISTINCREAMENT;//增加存储容量
	}
	q = &(L->elem[i - 1]);
	for (p = &(L->elem[L->length - 1]); p >= q; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++(L->length);
	return OK;
}

//判定是否为空表ListEmpty(L)
int ListEmpty(SqList *L)
{
	if (L->length == 0) 
	{
		return 0;
	}
	else
	return 1;
}

//求线性表的长度ListLength(L)
int ListLength(SqList *L)
{
	return(L->length);
}

//求某个数据元素值GetElem(L,i,e)
int GetElem(SqList L, int i, ElemType *e)
{
	if (i<1 || i>L.length)
		return 0;
	*e= L.elem[i - 1];
	return 1;
}



//按元素值查找LocateElem(L,e)
int LocateElem(SqList *L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->elem[i] != e) 
		i++;
	if (i >= L->length)
		return 0;
	else
		return i + 1;
}


//顺序表的删除,在L中删除第i个元素，并用e返回
int ListDelete_Sq(SqList *L, int i, ElemType *e)
{
	ElemType *q = 0;
	ElemType *p = 0;
	//i的合法值为1<=i&&i<=ListLength-Sq(L)-1
	if (i<1 || i>L->length - 1) //i输入不合法
		return ERROR;
	p = &(L->elem[i - 1]);  //p为被删除元素的位置
	*e = *p;  //被删除元素的值赋给e
	q = L->elem + L->length - 1;  //表尾元素的位置
	for (p=1 + p; p <= q; ++p)
	{
		*(p - 1) = *p;//剩下的元素右移
	}

	--(L->length);
	return OK;
}

//合并LA，LB，结果保存到A
void Union(SqList *LA, SqList LB)
{
	int i = 0;
	int e = 0;
	int LA_length = LA->length;
	int LB_length = LB.length;
	/*int *p = 0;
	p = &LB;*/
	for (i = 0; i < LB.length; i++)
	{
		//int temp =*(p+i);
		GetElem(LB,i,&e);
		//printf("%d\n", e);
		if (!LocateElem(LA, e))
		{
			
			ListInsert_Sq(LA, ++(LA->length), e);
		}
	}
}


//归并LA，LB为一个新表LC,仍按非值有序递减
void MergList(SqList LA, SqList LB, SqList *LC)
{
	InitList_Sq(LC);
	int i = 1;
	int j = 1;
	int k = 0;
	int ai = 0;
	int bj = 0;
	int LA_length = LA.length;
	int LB_length = LB.length;
	while ((i <= LA_length) && (j <= LB_length))
	{
		GetElem(LA,i,&ai);
		GetElem(LB,i,&bj);
		if (ai <= bj)
		{
			ListInsert_Sq(LC,++k,ai);
			++i;
		}
		else
		{
			ListInsert_Sq(LC, ++k, bj);
			++j;
		}
	}
	while (i <= LA_length)
	{
		GetElem(LA, i, &ai);
		ListInsert_Sq(LC, ++k, ai);
	}
	while (j <= LB_length)
	{
		GetElem(LB, i, &bj);
		ListInsert_Sq(LC, ++k,bj);
	}
}