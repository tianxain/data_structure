#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

// 初始化栈
void StackInit(Stack* pStack)
{
	assert(pStack);
	pStack->_a = NULL;
	pStack->_capacity = 0;
	pStack->_top = 0;
}

// 入栈
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

// 出栈
void StackPop(Stack* pStack)
{
	assert(pStack&&pStack->_top>0);
	--pStack->_top;
}

// 获取栈顶元素
STDataType StackTop(Stack* pStack)
{
	assert(pStack);
	return pStack->_a[pStack->_top - 1];
}

// 获取栈中有效元素个数
int StackSize(Stack* pStack)
{
	assert(pStack);
	return pStack->_top;
}

// 检测栈是否为空，如果不为空返回0，如果为空返回1
int StackEmpty(Stack* pStack)
{
	assert(pStack);
	return pStack->_top == 0 ? 1 : 0;
}

// 销毁栈
void StackDestroy(Stack* pStack)
{
	assert(pStack);
	free(pStack->_a);
	pStack->_a = NULL;
	pStack->_capacity = 0;
	pStack->_top = 0;
}