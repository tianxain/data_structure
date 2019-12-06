#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//静态栈
//#define N 10
//typedef struct Stack
//{
//	STDataType _a[N];
//	int _top; // 栈顶
//}Stack;

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;

// 初始化栈
void StackInit(Stack* pStack);
// 销毁栈
void StackDestroy(Stack* pStack);

// 入栈
void StackPush(Stack* pStack, STDataType x);
// 出栈
void StackPop(Stack* pStack);

// 获取栈顶元素
STDataType StackTop(Stack* pStack);

// 获取栈中有效元素个数
int StackSize(Stack* pStack);

// 检测栈是否为空，如果为空返回0，如果不为空返回1
int StackEmpty(Stack* pStack);
