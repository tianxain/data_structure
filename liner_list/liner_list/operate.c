#define _CRT_SECURE_NO_WARNINGS 1
#include"operate.h"
//����һ���յ����Ա�L
int  InitList_Sq(SqList *L)
{
	L->elem = (ElemType *)malloc(LIST_INT_SIZE * sizeof(ElemType));
	if (!L->elem)  //�洢����ʧ��
	{
		exit(OVERFLOW);
	}
	L->length = 0; //�ձ���Ϊ0
	L->listsize = LIST_INT_SIZE; ///��ʼ�洢����
	return OK;
}

//���Ա�����Ԫ��
int Input_Sq(SqList *L, int n)
{
	int i;
	int *newbase;
	if (n < 0)
		return ERROR;
	if (n >= L->listsize)//������ǰ�洢�ռ�
	{
		newbase = (ElemType *)malloc(LIST_INT_SIZE * sizeof(ElemType));
		if (!newbase)//�洢����ʧ��
		{
			exit(OVERFLOW);
		}
		L->elem = newbase;//�»�ַ
		L->listsize += LISTINCREAMENT;//���Ӵ洢����
	}
	printf("������Ԫ�أ�\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &L->elem[i]);
		L->length++;
	}
	return OK;
}

//������Ա�
int Output_Sq(SqList *L, int i)
{
	int j;
	printf("���Ա�Ϊ��\n");
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
	//i�ĺϷ�ֵΪ1<=i&&i<=ListLength-Sq(L)-1
	if (i<1 || i>L->length - 1) //i���벻�Ϸ�
		return ERROR;
	if (L->length >= L->listsize)//��ǰ�洢�ռ����������ӷ���
	{
		newbase = (ElemType *)realloc(L->elem,
			(LISTINCREAMENT + L->listsize) * sizeof(ElemType));
		if (!newbase)//�洢����ʧ��
		{
			exit(OVERFLOW);
		}
		L->elem = newbase;//�»�ַ
		L->listsize += LISTINCREAMENT;//���Ӵ洢����
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

//�ж��Ƿ�Ϊ�ձ�ListEmpty(L)
int ListEmpty(SqList *L)
{
	if (L->length == 0) 
	{
		return 0;
	}
	else
	return 1;
}

//�����Ա�ĳ���ListLength(L)
int ListLength(SqList *L)
{
	return(L->length);
}

//��ĳ������Ԫ��ֵGetElem(L,i,e)
int GetElem(SqList L, int i, ElemType *e)
{
	if (i<1 || i>L.length)
		return 0;
	*e= L.elem[i - 1];
	return 1;
}



//��Ԫ��ֵ����LocateElem(L,e)
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


//˳����ɾ��,��L��ɾ����i��Ԫ�أ�����e����
int ListDelete_Sq(SqList *L, int i, ElemType *e)
{
	ElemType *q = 0;
	ElemType *p = 0;
	//i�ĺϷ�ֵΪ1<=i&&i<=ListLength-Sq(L)-1
	if (i<1 || i>L->length - 1) //i���벻�Ϸ�
		return ERROR;
	p = &(L->elem[i - 1]);  //pΪ��ɾ��Ԫ�ص�λ��
	*e = *p;  //��ɾ��Ԫ�ص�ֵ����e
	q = L->elem + L->length - 1;  //��βԪ�ص�λ��
	for (p=1 + p; p <= q; ++p)
	{
		*(p - 1) = *p;//ʣ�µ�Ԫ������
	}

	--(L->length);
	return OK;
}

//�ϲ�LA��LB��������浽A
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


//�鲢LA��LBΪһ���±�LC,�԰���ֵ����ݼ�
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