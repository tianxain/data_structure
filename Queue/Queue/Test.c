#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void Test()
{
	Queue* qu;
	QueueInit(&qu);
	QueuePush(&qu,1);
	QueuePush(&qu,2);
	QueuePush(&qu,3);
	QueuePush(&qu,4);
	while (QueueEmpty(&qu) == 0)
	{
		printf("%d  ",qu->_front->_data);
		QueuePop(&qu);
	}
}
int main()
{
	Test();
	return 0;
}