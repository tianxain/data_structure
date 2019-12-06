#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

// ��ʼ��ջ
void StackInit(Stack* pStack)
{
	assert(pStack);
	pStack->_a = NULL;
	pStack->_capacity = 0;
	pStack->_top = 0;
}

// ��ջ
void StackPush(Stack* pStack, STDataType x)
{
	assert(pStack);
	if (pStack->_top== pStack->_capacity)
	{
		size_t newCapacity = pStack->_capacity == 0 ? 4 : pStack->_capacity * 2;
		pStack->_a = (STDataType*)realloc(pStack->_a, newCapacity *sizeof(STDataType));
	}
	pStack->_a[pStack->_top] = x;
	pStack->_top++;
}

// ��ջ
void StackPop(Stack* pStack)
{
	assert(pStack&&pStack->_top>0);
	--pStack->_top;
}

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* pStack)
{
	assert(pStack);
	return pStack->_a[pStack->_top - 1];
}

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* pStack)
{
	assert(pStack);
	return pStack->_top;
}

// ���ջ�Ƿ�Ϊ�գ������Ϊ�շ���0�����Ϊ�շ���1
int StackEmpty(Stack* pStack)
{
	assert(pStack);
	return pStack->_top == 0 ? 1 : 0;
}

// ����ջ
void StackDestroy(Stack* pStack)
{
	assert(pStack);
	free(pStack->_a);
	pStack->_a = NULL;
	pStack->_capacity = 0;
	pStack->_top = 0;
}