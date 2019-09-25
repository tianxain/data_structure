#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int ElemType;
#define INFEASIBLE -1
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define LIST_INT_SIZE 100 //���Ա�洢�ռ��ʼ������
#define LISTINCREAMENT 10  //���Ա�洢�ռ��������


typedef struct Sqlist {
	ElemType* elem;  //�洢�ռ��ַ
	int length;  //��ǰ����
	int listsize;//��ǰ����Ĵ洢����(��sizeof(int)Ϊ��λ)
}SqList;

//����һ���յ����Ա�L
int  InitList_Sq(SqList *L);

//���Ա�����Ԫ��
int Input_Sq(SqList *L, int n);

//������Ա�
int Output_Sq(SqList *L, int i);

//˳���Ĳ���,��L�е�i��λ��֮ǰ�����µ�Ԫ��e
int ListInsert_Sq(SqList *L, int i, ElemType e);

//˳����ɾ��,��L��ɾ����i��Ԫ�أ�����e����
int ListDelete_Sq(SqList *L, int i, ElemType *e);

//�ϲ�LA��LB��������浽A
void Union(SqList *LA, SqList LB);

//�鲢LA��LBΪһ���±�LC,�԰���ֵ����ݼ�
void MergList(SqList LA, SqList LB, SqList *LC);

//�ж��Ƿ�Ϊ�ձ�ListEmpty(L)
int ListEmpty(SqList *L);

//�����Ա�ĳ���ListLength(L)
int ListLength(SqList *L);

//��ĳ������Ԫ��ֵGetElem(L,i,e)
int GetElem(SqList L, int i, ElemType *e);

//��Ԫ��ֵ����LocateElem(L,e)
int LocateElem(SqList *L, ElemType e);