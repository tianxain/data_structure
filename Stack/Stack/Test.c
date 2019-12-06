#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
void Test()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	while (StackEmpty(&st) == 0)
	{
		printf("%d ",StackTop(&st));
		StackPop(&st);
	}
	StackDestroy(&st);
}
int main()
{
	Test();
	return 0;
}