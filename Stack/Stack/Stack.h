#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//��̬ջ
//#define N 10
//typedef struct Stack
//{
//	STDataType _a[N];
//	int _top; // ջ��
//}Stack;

// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // ջ��
	int _capacity; // ����
}Stack;

// ��ʼ��ջ
void StackInit(Stack* pStack);
// ����ջ
void StackDestroy(Stack* pStack);

// ��ջ
void StackPush(Stack* pStack, STDataType x);
// ��ջ
void StackPop(Stack* pStack);

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* pStack);

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* pStack);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ���0�������Ϊ�շ���1
int StackEmpty(Stack* pStack);
